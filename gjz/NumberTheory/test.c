#include <stdio.h>
int add(a, b)
    int a, b;
<%
    return a + b;
%>

int main()<%
    int a = 1, b = 1;
    printf("%d", add(a, b));
    return 0;
%>

