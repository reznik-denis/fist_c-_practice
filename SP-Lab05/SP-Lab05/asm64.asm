section .text
global multiply

multiply:
    mov rax, rdi       ; Отримуємо перший аргумент з регістра rdi
    imul rax, rsi      ; Множимо на другий аргумент з регістра rsi
    ret  
