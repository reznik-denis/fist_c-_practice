section .text
global multiply

multiply:
    mov rax, rdi       ; �������� ������ �������� � ������� rdi
    imul rax, rsi      ; ������� �� ������ �������� � ������� rsi
    ret  
