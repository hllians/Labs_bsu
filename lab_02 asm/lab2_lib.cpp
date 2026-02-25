#include "lab2_lib.h"
#include <spdlog/spdlog.h>
 
int calcExpration1(int a)
{
    if (a < 0)
        spdlog::warn("calcExpration1: a - negative ({})", a);

    int result = 0;
    __asm
    {
        mov eax, a
        mov ebx, eax
        imul eax, eax 
        mov ecx, eax 
        imul eax, a 
        add ebx, eax
        imul eax, ecx
        add ebx, eax 
        mov result, ebx
    }
    spdlog::info("calcExpration1({}) = {}", a, result);
    return result;
}

int calcExpration2(int a)
{
    if (a == 0)
    {
        spdlog::error("calcExpration2: division by zero (a=0)");
        return 0;
    }

    int result = 0;
    __asm
    {
        mov eax, a
        mov ecx, eax
        imul eax, eax
        mov edx, eax 
        mov eax, ecx 
        imul eax, edx 
        mov ebx, eax 
        imul eax, edx
        add eax, ecx       
        mov ecx, edx       
        add ecx, edx        
        sub ecx, 8        
        add eax, ecx 
        cdq        
        idiv ebx         
        
        mov result, eax
    }
    
    spdlog::info("calcExpration2({}) = {}", a, result);
    return result;
}

void add48(int16_t A1, int16_t A2, int16_t A3,
           int16_t B1, int16_t B2, int16_t B3,
           int16_t& C1, int16_t& C2, int16_t& C3)
{
    spdlog::info("add48: A = {:04X}{:04X}{:04X}, B = {:04X}{:04X}{:04X}",
                 uint16_t(A3), uint16_t(A2), uint16_t(A1),
                 uint16_t(B3), uint16_t(B2), uint16_t(B1));

    __asm
    {
        movzx eax, A1      
        movzx ebx, B1    
        add eax, ebx       
        mov cx, ax
        movzx eax, A2 
        movzx ebx, B2
        adc eax, ebx 
        mov dx, ax
        movzx eax, A3 
        movzx ebx, B3
        adc eax, ebx  
        mov C1, cx
        mov C2, dx
        mov C3, ax
    }

    spdlog::info("add48 result: C = {:04X}{:04X}{:04X}",
                 uint16_t(C3), uint16_t(C2), uint16_t(C1));
}