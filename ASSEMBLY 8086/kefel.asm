; multi-segment executable file template.

data segment
    ; add your data here!
    give db "Give a number...$"
    giveSecond db "Give a second number...$"
    tryAgain db "The input is not a number, please try again$"
    firstNumber db 0
    secondNumber db 0
    line db 10,13,'$'
ends

stack segment
    dw   128  dup(0)
ends

code segment

getAnumber proc
    over:  mov ah,1
      int 21h
      cmp al, 'k'
      je goodNumber
      cmp al, '9'
      ja again
      cmp al, '0'
      jb again
      jmp goodNumber
     again:
      lea dx, line
      mov ah, 9
      int 21h
      
      mov ah, 9
      lea dx, tryAgain
      int 21h
      
      lea dx, line
      mov ah, 9
      int 21h
      
      jmp over
     goodNumber:  
      xor ah, ah
      ret
getAnumber endp

start:
; set segment registers:
    mov ax, data 
    mov ds, ax
    mov ax, 0b800H 
    mov es, ax 
    xor ax, ax
     
    mov di, 0
    cld

todo:    
    lea dx, give
    mov ah, 9
    int 21h
    call getAnumber
    cmp al, 'k'
    je outt
    mov firstNumber, al
    
    lea dx, line
    mov ah, 9
    int 21h
    
    lea dx, giveSecond
    mov ah, 9
    int 21h
    call getAnumber
    cmp al, 'k'
    je outt
    mov secondNumber, al
     
    lea dx, line
    mov ah, 9
    int 21h
    
    xor ax,ax
    mov dl, firstNumber
    sub dl, 30h
    mov al, secondNumber
    sub al, 30h
    
    mul dl
    push ax
    push ax
BASIS16:    
    mov cl, 16
    div cl
    mov dl, al
    cmp dl, 0Ah
    jb nott
    add dl, 7
    nott: add dl, 30h
    mov ch, ah
    mov ah, 2  
    int 21h
    
    mov dl, ch
    cmp dl, 0Ah
    jb nott2
    add dl, 7
    nott2: add dl, 30h 
    mov ah, 2  
    int 21h
    
    mov dl, 'h'
    mov ah, 2  
    int 21h     
    
    
    lea dx, line
    mov ah, 9
    int 21h
    
BASIS10:
    pop ax
    AAM
    
    mov dl, ah
    add dl, 30h
    mov ch, al
    mov ah, 2  
    int 21h
    
    mov dl, ch
    add dl, 30h
    mov ah, 2  
    int 21h
    
    lea dx, line
    mov ah, 9
    int 21h

BASIS2:
    mov cl, 2
    pop ax
    
lop:    
    div cl
    mov ah, dl
    mov ah, 2
    add dl, 30
    int 21h
    xor ah,ah
    cmp al, 0
    ja lop
    
    
    
    jmp todo 

outt:    

    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
