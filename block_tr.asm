data SEGMENT
    block1 db 01h,02h,03h,04h,05h
    block2 db 5 dup(0)
data ENDS

code SEGMENT
    assume cs:code, ds:data
    START:
    mov ax,data
    mov ds,ax
    mov es,ax
    lea si,block1       ;load effective address of block1 in source index
    lea di,block2       ;lea of block2 in destination index
    mov cx,05h
    cld                 ;clear direction flag - data moves forward (increments) after each byte
    rep movsb           ;repeat movsb instruction cx times - copies bytes from ds:si to es:di
    mov ah,4ch
    int 21h
code ENDS
END START