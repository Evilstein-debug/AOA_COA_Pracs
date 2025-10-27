DATA SEGMENT
msg  DB 0Dh,0Ah, "-- -- -- -- OF DF IF TF SF ZF -- AF -- PF -- CF $"
newl DB 0Dh,0Ah, "$"
flag DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    ; Print flag names line
    MOV DX, OFFSET msg
    MOV AH, 09h
    INT 21h

    ; Print newline
    MOV DX, OFFSET newl
    MOV AH, 09h
    INT 21h

    ; Get flag register into BX
    PUSHF
    POP BX
    MOV flag, BX

    MOV CX, 10h       ; 16 bits total
    MOV BX, 8000h     ; start with MSB (bit 15 = high bit)

DISPLAY_LOOP:
    MOV AX, flag
    AND AX, BX        ; isolate current bit
    JZ PRINT_ZERO

PRINT_ONE:
    MOV DL, '1'
    MOV AH, 02h
    INT 21h
    JMP PRINT_SPACE

PRINT_ZERO:
    MOV DL, '0'
    MOV AH, 02h
    INT 21h

PRINT_SPACE:
    MOV DL, ' '       ; print space between bits
    MOV AH, 02h
    INT 21h

    ROR BX, 1         ; rotate mask right by 1 (next bit)
    LOOP DISPLAY_LOOP

    ; Exit program
    MOV AH, 4Ch
    INT 21h

CODE ENDS
END START
