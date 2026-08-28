class Veiculo:

    def __init__(self, nome, marca, modelo):

        #Variaveis de INSTANCIA
        self.nome = nome
        self.marca = marca
        self.modelo = modelo


    def metodo1(self):
        pass

    def metodo2(self):
        pass

    def metodo3(self):
        pass


class Moto(Veiculo): #Classe moto HERDA de veiculo

    #super().metodo() : Basicamente, executa o metodo "metodo" da classe pai.
#                       "como" se o objeto atual fosse dessa classe do pai.
#                       Util para repetir comportamentos.
    #No caso do init, é ideal que o método super seja utilizado, exceto em casos que o comportamento muda.
    #OBS : Caso o super() não seja utilizado, no caso do init, variaveis de INSTANCIA não seriam declaradas.
    #OBS : super() acessa a classe "acima" da atual. Portanto, é possível utilizar essa metodologia
    #do super.method para outras funções, CASO SEJA DESEJADO. Util para comportamentos repetidos.
    def __init__(self, nome, marca, modelo, cilindrada = 100):
        #Super.__init__ : Executa o init da sua classe acima. Util para repetir padrões.
        #Caso não fosse chamado, as variaveis de INSTANCIA usadas no init da classe pai não seriam declaradas
        super().__init__(nome, marca, modelo) 
        self.cilindrada = cilindrada


    # def metodo1(self): #Caso não existam diferenças, não é necessário declarar.
    #     pass


    def metodo2(self):
        #Sobrescreve o metodo herdade da classe pai por o que está abaixo.
        #Funciona mesmo se tiver uma assinatura (parametros) a diferente (a mais), mas neste caso, recomenda-se usar valores opcionais.
        pass

    def metodo3(self):
        #Sobrescreve o metodo 3, mas devido ao super, repete o codigo do metodo3 do pai.
        #Em seguida, faz algo a mais que não é feito no metodo3 da classe pai
        #Util quando o comportamento do metodo3 se repete e, depois, acrescenta-se o comportamento diferente.
        super().metodo3() #Repete o comportamento da classe pai

        #Faz algo extra.

        


moto = Moto('Yamaha', 'minha marca', 'meu modelo')

moto.cilindrada = 120
moto.nome #Funciona, devido ao super. Sem o super, este atributo não existiria

moto.metodo1() #Funciona, pois a classe Moto herdou todos os metodos (e atributos) da classe pai
moto.metodo2() #Funciona.
moto.metodo3() #Funciona.



# Mecanismos para complementar OU evitar herança
#Composition:
#Ao invés de criar uma classe nova para acrescentar uma funcionalidade, faz-se uma classe apenas para aquele tipo de funcionalidade
#e, depois, adiciona-a como objeto a classe alvo.
#Por exemplo, ao invés de criar as subclasses RoboComSensorDistancia, RoboComSensorDistanciaAprimorado,RoboComSensorRadio
#basta dizer que a classe Robo tem um atributo "sensor", que será um objeto da classe Sensor.
#Portanto, bastaria que robo fizesse self.sensor.executar()


#Ducktyping
#Basicamente, ao invés de "amarrar" classes distintas com herança, faz-se um contrato IMPLICITO
#que todas as classes alvos deverão ter um (ou mais) métodos com a mesma assinatura (ou em caso de parametros diferentes, opcionais).
#Desta forma, todas possuem o mesmo metodo e, depois, basta chamar: Objeto_que_nao_sei_a_classe._metodo_comum_a_todos()


