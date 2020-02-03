; multi-segment executable file template.

data segment
    ; add your data here!
    h db "students Amal Aleph PETACH TIKVA$"
    newline db 0ah, 0dh, "$"
    counter db 0
    
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
    cld
    ; add your code here
            
    mov dx, offset h
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    mov ah, 0
    mov si, 0
    mov cx, 20
    
Again:    lodsb
    cmp al, 'A'
    jne next
    inc counter
next: loop Again    
    
    mov dl, counter
    add dl, 30h
    mov ah, 2
    int 21h 
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
