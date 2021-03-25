#include <stdio.h>

// STRUCTS \\

struct $
{
    int sp;
    int valores[MAX];    
};


struct s a, b[40];

a.sp = 5                    // A componente sp de a passa a 5 
a.valores[3] = 42;                      
b[2].sp = 3;
b[3].valores[5] = 44;


// Proxima aula : passagem de structs como argumentos