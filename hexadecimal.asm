DATA SEGMENT
    msg1 db 0ah,0dh, "Enter two digit hexadecimal number: $"
    msg2 db 0ah,0dh, "Your entered number is: $"
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    mov ax,DATA
    mov ds,ax

    mov dx,OFFSET msg1
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
    sub al,30h
    mov cl,04h
    rol al,cl
    mov bl,al

    mov ah,01h
    int 21h
    sub al,30h
    add bl,al           ;bl now contains final hex numeric value

    mov dx,OFFSET msg2
    mov ah,09h
    int 21h

    mov al,bl
    and al,0F0h         ;mask lower nibble
    mov cl,04h
    ror al,cl
    add al,30h          ;convert numeric value to ascii
    mov dl,al
    mov ah,02h
    int 21h

    mov al,bl
    and al,0Fh          ;mask upper nibble
    add al,30h
    mov dl,al
    mov ah,02h
    int 21h

    mov ah,4ch
    int 21h

CODE ENDS
END START