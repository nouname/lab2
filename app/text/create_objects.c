#include "_text.h"

text create_objects()
{
    text txt;

    /* Создаем структуру описания текста */
    txt = (list *)malloc(sizeof(list));

    /* Создаем структуру описания курсора */
    txt->cursor = (txt->cursor = (crsr *)malloc(sizeof(crsr)));
    return !txt || !txt->cursor ? NULL : txt;
}
