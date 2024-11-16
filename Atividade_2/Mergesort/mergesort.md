# Este documento apresenta os resultados de testes de desempenho do algoritmo Merge Sort em diferentes cenários: Melhor Caso, Caso Médio e Pior Caso.

## Definições de Caso

1. **Melhor Caso**: Ocorre quando o vetor já está previamente ordenado em ordem crescente. Apesar de o Merge Sort realizar o mesmo número de divisões e fusões independentemente da ordem inicial, o acesso sequencial aos dados pode proporcionar um leve ganho de desempenho devido à eficiência no uso da memória.
2. **Caso Médio**: Refere-se ao desempenho esperado quando o vetor é gerado de forma aleatória. Este cenário apresenta o comportamento típico do algoritmo ao processar dados sem nenhum padrão aparente.
3. **Pior Caso**: Ocorre quando o vetor está ordenado em ordem decrescente. Apesar de o número de operações do Merge Sort ser consistente para qualquer entrada, a forma como os elementos são armazenados e manipulados pode gerar variações mínimas no tempo de execução.

-------------------------------------------------------------------------------------------------------

# Testes de Desempenho do Merge Sort

## Melhor Caso

Vetor original (melhor caso - ja ordenado):
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
Mergesort com vetor ja ordenado: Tempo de execucao: 0.000009 segundos

Vetor ordenado:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 

## Caso Médio

640 249 657 345 208 829 483 698 733 444 260 897 723 105 697 730 676 450 563 944 911 213 167 891 642 697 282 442 5 560 564 859 877 815 819 325 892 653 837 951 24 270 842 123 548 18 734 611 797 744 690 613 166 161 567 124 927 417 519 34 479 682 183 992 385 928 865 111 182 805 856 432 24 312 856 222 69 763 740 781 74 369 215 298 279 776 515 558 876 0 928 455 281 716 860 676 486 378 664 234 
Mergesort com vetor aleatorio: Tempo de execucao: 0.000014 segundos

Vetor ordenado:
0 5 18 24 24 34 69 74 105 111 123 124 161 166 167 182 183 208 213 215 222 234 249 260 270 279 281 282 298 312 325 345 369 378 385 417 432 442 444 450 455 479 483 486 515 519 548 558 560 563 564 567 611 613 640 642 653 657 664 676 676 682 690 697 697 698 716 723 730 733 734 740 744 763 776 781 797 805 815 819 829 837 842 856 856 859 860 865 876 877 891 892 897 911 927 928 928 944 951 992 

## Pior Caso

Vetor original (pior caso - ordem decrescente):
100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
Mergesort com vetor em ordem decrescente: Tempo de execucao: 0.000015 segundos

Vetor ordenado:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 