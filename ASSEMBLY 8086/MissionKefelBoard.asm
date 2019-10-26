; multi-segment executable file template.

data segment
    kefel db 100 dup(0)  
    
    pkey db "press any key...$" 
    
    data ends

stack segment
    dw   128  dup(0)
    stack ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    
    mov si, offset kefel
    mov cx, 10
    mov bl, 0 
again:
    inc bl
    mov bh, 1 
    push cx
    mov cx, 10
again2:
    mov al, bh    
    mul bl 
    mov [si], al
    inc bh
    inc si
    loop again2
    pop cx
    loop again
    
    code ends

end start ; set entry point and stop the assembler.
