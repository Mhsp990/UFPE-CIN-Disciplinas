LADO_GRADE = 10
x = 0
y = 0
direcao = "LESTE"

comandos = ["AVANCAR 3", "GIRAR ESQ", "AVANCAR 2", "GIRAR DIR", "AVANCAR 5", "PARAR"]

trajetoria = [(x, y)]   # worked: estado antes de qualquer comando

for cmd in comandos:
    partes = cmd.strip().upper().split()
    acao = partes[0]
    if acao == "PARAR":
        print("Robô parou.")
        break
    if acao == "AVANCAR":
        passos = int(partes[1])
        if direcao == "LESTE":
            novo_x = x + passos
            if 0 <= novo_x < LADO_GRADE:
                x = novo_x
                trajetoria.append((x, y))
            else:
                print("  Parede! Ficou em x =", x)
        elif direcao == "NORTE":
            novo_y = y + passos
            if 0 <= novo_y < LADO_GRADE:
                y = novo_y
                trajetoria.append((x, y))
            else:
                print("  Parede! Ficou em y =", y)
        elif direcao == "OESTE":
            novo_x = x - passos
            if 0 <= novo_x < LADO_GRADE:
                x = novo_x
                trajetoria.append((x, y))
            else:
                print("  Parede! Ficou em x =", x)
        elif direcao == "SUL":
            novo_y = y - passos
            if 0 <= novo_y < LADO_GRADE:
                y = novo_y
                trajetoria.append((x, y))
            else:
                print("  Parede! Ficou em y =", y)
    elif acao == "GIRAR":
        lado = partes[1]
        if lado == "ESQ":
            if direcao == "LESTE":    direcao = "NORTE"
            elif direcao == "NORTE":  direcao = "OESTE"
            elif direcao == "OESTE":  direcao = "SUL"
            elif direcao == "SUL":    direcao = "LESTE"
        elif lado == "DIR":
            if direcao == "LESTE":    direcao = "SUL"
            elif direcao == "SUL":    direcao = "OESTE"
            elif direcao == "OESTE":  direcao = "NORTE"
            elif direcao == "NORTE":  direcao = "LESTE"
    print(f"  [{acao}] Robô em ({x}, {y}), direção {direcao}")

print("Trajetória percorrida:", trajetoria)