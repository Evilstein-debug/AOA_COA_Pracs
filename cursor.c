#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main() {
int choice;
char count = 0;
while (1) {
clrscr();
printf("\nCursor Control Menu:\n");
printf("1. Increment Cursor Size\n");
printf("2. Decrement Cursor Size\n");
printf("3. Disable Cursor (Hide)\n");
printf("4. Exit\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
if (count >= 4) {
printf("Maximum cursor size reached.");
} else {
count++;
union REGS regs;
regs.h.ah = 0x01;
regs.h.ch = 0x00;
regs.h.cl = count;
int86(0x10, &regs, &regs);
printf("Cursor size increased.");
}
break;
case 2:
if (count <= 0) {
printf("Minimum cursor size reached.");
} else {
count--;
union REGS regs;
regs.h.ah = 0x01;
regs.h.ch = 0x00;
regs.h.cl = count;
int86(0x10, &regs, &regs);
printf("Cursor size decreased.");
}
break;
case 3: {
union REGS regs;
regs.h.ah = 0x01;
regs.h.cl = 0x20;
int86(0x10, &regs, &regs);
printf("Cursor hidden.");
}
break;
case 4:
exit(0);
default:
printf("Invalid choice.");
}
getch();
}
return 0;
}