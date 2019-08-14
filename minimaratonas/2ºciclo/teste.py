#!/bin/python3

# Provavelmente busca binaria nesse intervalo - voltar dps
import math
import os
import random
import re
import sys

# Complete the introTutorial function below.    
def func(valor, qtd, moedas):
    i = qtd - 1
    contador = 0
    moedas.sort()
    
    while valor > 0 and i >= 0:
        div = int(valor/moedas[i])
        contador += div
        valor = valor - moedas[i]*div
        i = i - 1
        
    print(contador)
            
if __name__ == '__main__':
    while True:
        try:
            nm = input().split()
            nm = [int(i) for i in nm]
            
            i = 0
            moedas = []
            
            while i< nm[0]:
                c = input()
                c = int(c)
                moedas.append(c)
                i = i + 1
            
            func(nm[1], nm[0], moedas)
                
        except EOFError:
            break

