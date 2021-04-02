// S005.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Приветствую\n";

    char s[256];
    char s2[256];

    char f[] = "%s";

    char fd[] = "%d\n";

    _asm {
        //вводим 1 строку
        lea esi, s
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi
        //вводим 2 строку
        lea esi, s2
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi
        //Поиск подстроки
        lea ebx, s
        dec ebx
        lea ecx, s2
        b1 :
        inc ebx
            mov al, [ebx]
            cmp al, 0
            je b5
            cmp al, [ecx]
            jnz b1
            mov edx, ebx
            b2 :
        inc ebx
            inc ecx
            mov al, [ebx]
            cmp al, 0
            je b3
            mov al, [ecx]
            cmp al, 0
            je b4
            cmp al, [ebx]
            je b2
            mov ebx, edx
            lea ecx, s2
            jmp b1
            b3 :
        mov al, [ecx]
            cmp al, 0
            jne b5
            b4 :
        lea ebx, s
            add ebx, -1
            sub edx, ebx
            push edx
            jmp b6
            //Вывод результата
            b5 :
        mov ebx, -1
            push ebx
            b6 :
        lea ebx, fd
            push ebx
            call printf
            add esp, 8
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
