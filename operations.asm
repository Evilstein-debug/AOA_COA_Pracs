DATA SEGMENT
    NUM1 DB 24H
    NUM2 DB 11H
    RES  DW ?     ; to store results if needed
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    ; ADDITION
    MOV AL, NUM1
    MOV BL, NUM2
    ADD AL, BL        ; AL = NUM1 + NUM2

    ; SUBTRACTION
    MOV AL, NUM1
    SUB AL, BL        ; AL = NUM1 - NUM2

    ; MULTIPLICATION
    MOV AL, NUM1
    MOV BL, NUM2
    MUL BL            ; AX = AL * BL (unsigned)

    ; DIVISION
    MOV AL, NUM1
    MOV AH, 00H       ; clear AH for 8-bit division
    MOV BL, NUM2
    DIV BL            ; AL = quotient, AH = remainder

    ; AND
    MOV AL, NUM1
    MOV BL, NUM2
    AND AL, BL

    ; OR
    MOV AL, NUM1
    OR AL, BL

    ; XOR
    MOV AL, NUM1
    XOR AL, BL

    ; NOT
    MOV AL, NUM1
    NOT AL

    MOV AH, 4CH       ; exit to DOS
    INT 21H

CODE ENDS
END START
