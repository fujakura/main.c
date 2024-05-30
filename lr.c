#define _CRT_SECURE_NO_WARNINGS
#include "lr.h"

#define p 3.14
#define YES 1
#define NO 0
#define MAXLINE 1000
#define N 10
#define Kk 3
#define Nn 4
#define INT_MAX 12000
#define INT_MIN 1000
#define MASK0 0x55555555 
#define MASK1 0xaaaaaaaa 


int is_vowel(char ch)
{
    ch = (ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int remainingfigure()
{
    float r = 0.0;
    float a = 0.0;
    float s1 = 0.0;
    float s2 = 0.0;

    printf("r = ");
    scanf("%f", &r);

    printf("a = ");
    scanf("%f", &a);

    s1 = p * r * r;
    s2 = a * a;
    s1 = s1 - s2;

    printf("square = %f\n", s1);

    return 0;
}

int stroka()
{
    float s; // ����� ����
    float a; // ��������� ������� ����
    int c; // ��������� ���������� �������� ����
    int b; // ����������� ���������� �������� ����
    int n; // ����� ��������� ����
    int i; // ����� ���������� �������� ����
    int sign; // ���� ���������� �������� ����
    int x;
    int w;

    // ���� ���������� ����
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%d", &x);

    // ��������� ������������ ����������
    s = 0;
    sign = 1;
    i = 0;
    b = 1;
    c = x;
    w = 1;

    // ����
    for (i = 0; i < n; i++)
    {
        c = x;
        for (int j = 1; j < w; j++)
        {
            c = c * x;
        }

        b = 1;
        for (int k = 1; k <= w; k++)
        {
            b = b * k;
        }

        a = (float)c / b;
        s = s + a * sign;
        sign = -sign;
        w = w + 2;
    }

    // ����� ����������
    printf("s = %.2f\n", s);


    return 0;
}

int string()
{
    int c;
    int first;
    int last;
    int endofword = YES;
    int count = 0;

    while ((c = getchar()) != '\n')
    {
        if (endofword == YES)
        {
            first = c;
            endofword = NO;
        }

        if (c == ' ' || c == '.' || c == '\n' || c == ',')
        {
            endofword = YES;

            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' || first == 'y')
            {
                if (!(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u' || last == 'y'))
                {
                    count += 1;
                }
            }
        }
        last = c;
    }

    printf("count: %d\n", count);

    return 0;
}

int glasn2()
{
    char str[100];
    printf("Stroka: ");
    fgets(str, 100, stdin);

    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (is_vowel(str[i]) && is_vowel(str[i + 1]))
        {
            i += 2;
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';

    // ����� ��������������� ������
    printf("Otf Stroka: %s\n", str);

    return 0;
}

int massiv()
{
    int x[N]; // ������ �� N ���������
    int sumchet = 0; // ����� ������ �����
    int sumnechet = 0; // ����� �������� �����
    int i;

    // ���� �������
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
        if (x[i] % 2 == 0) // ���� ����� ������
            sumchet += x[i];
        else
            sumnechet += x[i];
    }

    // ����� ���������� �����
    if (sumchet > sumnechet)
        printf("naib-i symma: %d\n", sumchet);
    else
        printf("naib-i symma: %d\n", sumnechet);

    return 0;
}

int dvmassiv()
{
    int x[Kk][Nn];
    int min = INT_MAX;
    int max = INT_MIN;
    int i, j;

    // ���� �������
    printf("Vvedite elementi massiva %dx%d:\n", Kk, Nn);

    for (i = 0; i < Kk; i++)
    {
        for (j = 0; j < Nn; j++)
        {
            scanf("%d", &x[i][j]);

            // ���������� ������������ � ������������� ���������
            if (x[i][j] < min)
            {
                min = x[i][j];
            }
            if (x[i][j] > max)
            {
                max = x[i][j];
            }
        }
    }

    // ������ ���������
    for (i = 0; i < Kk; i++)
    {
        for (j = 0; j < Nn; j++)
        {
            if (x[i][j] < 0)
            {
                x[i][j] = min;
            }
            else
            {
                x[i][j] = max;
            }
        }
    }

    // ����� ����������� �������
    printf("\nIzm. massiv:\n");
    for (i = 0; i < Kk; i++)
    {
        for (j = 0; j < Nn; j++)
        {
            printf("%4d ", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int bits()
{
    long z; // �������� �����
    unsigned long y; // ����������� ������ ��������� �����
    unsigned long mask; // �����
    int counter0 = 0; // ������� ������ �������
    int counter1 = 0; // ������� �������� �������
    int i;

    mask = 1;

    printf("z = ");
    scanf("%lx", &z); // ���� � ����������������� �������

    y = (unsigned long)z;

    while (y != 0)
    {
        counter0 += y & mask;
        y >>= 1;
        counter1 += y & mask;
        y >>= 1;
    }

    if (counter0 != counter1)
    {
        mask = counter0 > counter1 ? MASK1 : MASK0;
        z = z & ~mask;
    }

    printf("result: %lx\n", z);

    return 0;
}


int squaringfunction()
{
    float a = 0.0;

    printf("a = ");
    scanf("%f", &a);

    a = a * a;

    printf("square = %f\n", a);

    return 0;
}

int cyclefor()
{

    float s; // ����� ����
    float a; // ��������� ������� ����
    int c; // ��������� ���������� �������� ����
    int b; // ����������� ���������� �������� ����
    int n; // ����� ��������� ����
    int i; // ����� ���������� �������� ����
    int sign; // ���� ���������� �������� ����
    int x;
    int w;
    // ���� ���������� ����
    printf("n=");
    scanf("%d", &n);
    printf("x=");
    scanf("%d", &x);
    // ��������� ������������ ����������
    s = 0;
    sign = 1;
    i = 0;
    b = 1;
    c = x;
    w = 1;
    // ����
    for (i = 0; i < n; i++)
    {
        c = x;
        for (int j = 1; j < w; j++)
        {
            c = c * x;
        }
        b = 1;
        for (int k = 1; k <= w; k++)
        {
            b = b * k;
        }
        a = (float)c / b;
        s = s + a * sign;
        sign = -sign;
        w = w + 2;
    }
    // ����� ����������
    printf("s = %.2f\n", s);

    return 0;
}

