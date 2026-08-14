LADO_GRADE = 10

DELTAS    = {"LESTE": (1, 0), "NORTE": (0, 1), "OESTE": (-1, 0), "SUL": (0, -1)}
GIRAR_ESQ = {"LESTE": "NORTE", "NORTE": "OESTE", "OESTE": "SUL", "SUL": "LESTE"}
GIRAR_DIR = {"LESTE": "SUL", "SUL": "OESTE", "OESTE": "NORTE", "NORTE": "LESTE"}

grade = [[0] * LADO_GRADE for _ in range(LADO_GRADE)]
obstaculos = {(3, 2): True, (5, 5): True, (7, 1): True}

robo = {"x": 0, "y": 0, "direcao": "LESTE", "trajetoria": [(0, 0)]}

comandos = ["AVANCAR 3", "GIRAR ESQ", "AVANCAR 5", "GIRAR DIR", "AVANCAR 4", "PARAR"]

for cmd in comandos:
    partes = cmd.strip().upper().split()
    acao = partes[0]
    if acao == "PARAR":
        print("Robô parou.")
        break

    if acao == "AVANCAR":
        passos = int(partes[1]) # Lista partes[acao, passos], sem validação
        dx, dy = DELTAS[robo['direcao']] #
        for _ in range(passos):
            dx, dy = DELTAS[robo['direcao']]  #Calcula a direção "vetor" para somar com a posição atual. Anda um ÚNICO passo
            nx, ny = robo['x'] + dx, robo['y'] + dy
            if (0 <= nx < LADO_GRADE and
                0 <= ny < LADO_GRADE and
                (nx, ny) not in obstaculos):
                robo['x'], robo['y'] = nx, ny
                robo['trajetoria'].append((nx,ny)) #A chave 'trajetoria' contem uma lista de tuplas, que contem o percurso pecorrido.
            else:
                pass
    
    elif acao == "GIRAR":
        lado = partes[1]
        if lado == "ESQ":
            robo["direcao"] = GIRAR_ESQ[robo["direcao"]]
        elif lado == "DIR":
            robo["direcao"] = GIRAR_DIR[robo["direcao"]]

    # TODO (Passo 1): elif acao == "AVANCAR" — andar direto na direção atual,
    # sem checar parede nem obstáculo ainda (de propósito).
    # TODO (Passo 2): trocar o corpo do AVANCAR por um `for _ in range(passos)`
    # que anda um passo por vez, checando 0 <= nx < LADO_GRADE e (nx, ny) not in obstaculos.
    # TODO (Passo 3): elif acao == "GIRAR" — atualizar robo["direcao"] usando
    # GIRAR_ESQ/GIRAR_DIR.
    print(f"  [{acao}] Robô em ({robo['x']}, {robo['y']}), direção {robo['direcao']}")

# TODO (Passo 3): fora do loop, imprimir a trajetória final.
# print(f"Trajetória: {robo['trajetoria']}")
