data SEGMENT
    string1 db 01h,02h,03h,04h,05h
    string2 db 06h,07h,08h,09h,10h
    string3 db 5 dup(0)
data ends

code SEGMENT
    assume cs:code, ds:data
    start:
    mov ax,data
    mov ds,ax
    mov es,ax

    lea si,string1
    lea di,string3

    mov cx,05h
    cld                 ;clear direction flag
    rep movsb           ;repeat movsb instruction cx times

    lea si,string2
    lea di,string1

    mov cx,05h
    cld
    rep movsb

    lea si,string3
    lea di,string2

    mov cx,05h
    cld
    rep movsb

    mov ah,4ch
    int 21h

code ends
end start
