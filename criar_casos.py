from random import randint
import sys, os


def main():
    total = 12
    max_quant = 12
    max_nums = 500
    
    print(f"CRIANDO AQUIVOS")

    if not os.path.exists("./meus_casos/"):
        os.makedirs("./meus_casos/")

    for i in range(total):
        with open(f"./meus_casos/{i + 1}.in", "w") as f:
            tamanhoA = randint(1,max_quant * (i+1)) 
            tamanhoB = randint(1,max_quant * (i+1))

            f.write(f"{tamanhoA}\n")
            f.write(f"{tamanhoB}\n")

            for _ in range(tamanhoA):
                f.write(f"{randint(1,max_nums)} ")
            f.write("\n")
            for _ in range(tamanhoB):
                f.write(f"{randint(1,max_nums)} ")

            f.write("\n")
            
            op = randint(1,4)
            f.write(f"{op}\n")

            if op == 1 or op == 4:
                f.write(f"{randint(1,max_nums)}")
        
        print(f"./meus_casos/{i + 1}.in criado com sucesso")

if __name__ == "__main__":
    main()