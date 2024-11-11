clc;
clear all;
close all;
code_length=0;
x=input('Enter number of symbols: ');
for m=1:x
symbols(m)=input('Enter the symbol number: ');
p(m)=input('Enter the probability: ');
end
Hx=0
for m=1:x
[dict,avglen]=huffmandict(symbols,p)
hcode=huffmanenco(m,dict)
dsig = huffmandeco(hcode,dict)
code_length=length(hcode)
Hx=Hx+(p(m)*(-log(p(m)))/(log(2)));
end
display(Hx);
Efficiency=(Hx/avglen)*100
Disp(Efficiency);