; multi-segment executable file template.

data segment
    ; add your data here!
    h db "hello students$"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data 
    mov ds, ax
    mov ax, 0b800H 
    mov es, ax 
    xor ax, ax
    mov di, 0
    cld
             
             
    mov cx, 5
    mov ah,24h
    mov al,[di]
        
    rep stosw
    
    add di, 2
    mov cx, 8
    mov ah,042h
    mov al,[di]
    rep stosw
       
    ; add your code here
    mov dx, offset h        
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
