Algoritmo Menú_de_Programas
	
	Repetir
		Borrar Pantalla
		Escribir 'MENÚ DE OPCIONES'
		Escribir '================================================================='
		Escribir '1- Porcentaje de determinada cantidad'
		Escribir '2- Salario del Trabajador'
		Escribir '3- Promedio de módulo'
		Escribir '4- SALIR'
		Escribir 'Selecciona una Opción : '
		Leer Opción
		
		Segun Opción  Hacer
			1:
				Borrar Pantalla
			    Escribir '=======Calcular el porcentaje de determinada cantidad========== '
			    Definir monto,porcentaje,resultado  Como real
				Escribir "Introduce el monto de la cantidad... "
				leer monto
				Escribir "Introduce el Porcentaje... "
				leer porcentaje
				resultado=(monto*porcentaje)/100
				Escribir "El resultado de calcular el " ,porcentaje "% de $" ,monto " es $" ,resultado
				Escribir '¿Quieres realizar otro porcentaje? S/N '
				Leer Resp
				Si Resp="S" Entonces
					
					Repetir
						Borrar Pantalla
						Escribir '=======Calcular el porcentaje de determinada cantidad========== '
						Escribir "Introduce el monto de la cantidad... "
						leer monto
						Escribir "Introduce el Porcentaje... "
						leer porcentaje
						resultado=(monto*porcentaje)/100
						Escribir "El resultado de calcular el " ,porcentaje "% de $" ,monto " es $" ,resultado
						Escribir '¿Quieres realizar otro porcentaje? S/N '
						Leer Resp
					Hasta Que Resp='N'
				fin si
			2:
				Borrar pantalla
				Definir HrT,HrEx Como Entero
				Definir CostoHrN,SalPar,SalHrEx,SalarioF,Estim Como Real
				Escribir "====Calcula el salario del trabajador===="
				Escribir "Introduce el nombre del trabajador"
				leer NomT
				Escribir "Introduce el Número de horas trabajadas"
				leer HrT
				Escribir "Introduce el costo por hora normal"
				leer CostoHrN
				Si HrT>48 Entonces
					SalPar=48*CostoHrN
					HrEx=HrT-48
					Limpiar Pantalla
					Escribir , NomT " Tiene ", HrEx " Horas Extras"
					Escribir "El salario Parcial de ", NomT " Es: $", SalPar
					SalarioF=SalPar+(HrEx*(CostoHrN*2))
					Escribir "El salario de ", NomT " con Horas extras es: $", SalarioF
					Si SalarioF>5000 Entonces
						Escribir , NomT " Haz ganado un Estímulo del 5%"
						SalarioF=SalarioF+(SalarioF*.05)
						Escribir "Tu salario con estímulo es de : $", SalarioF
					SiNo 
						Escribir , NomT " No Tienes Horas Extras"
						Escribir , NomT " Tu salario Sin estímulo es de : $", SalarioF
						Escribir "Suerte para la próxima"
					Fin Si
					
				SiNo
					SalarioF=HrT*CostoHrN
					Si SalarioF>5000 Entonces
						Limpiar pantalla
						Escribir , NomT " No Tienes Horas Extras"
						Escribir "Aún así, Haz ganado un Estímulo del 5%"
						SalarioF=SalarioF+(SalarioF*.05)
						Escribir "Tu salario con estímulo es de : $", SalarioF
					SiNo
						Limpiar pantalla
						Escribir , NomT " No Tienes Horas Extras"	
						Escribir , NomT " Tu salario Sin estímulo es de : $", SalarioF
						Escribir "Suerte para la próxima"
					FinSi
				FinSi
				Escribir '¿Quieres realizar otro cálculo? S/N '
				Leer Resp
				Si Resp="S" Entonces
					
					Repetir
						Borrar pantalla	
						Escribir "====Calcula el salario del trabajador===="
						Escribir "Introduce el nombre del trabajador"
						leer NomT
						Escribir "Introduce el Número de horas trabajadas"
						leer HrT
						Escribir "Introduce el costo por hora normal"
						leer CostoHrN
						Si HrT>48 Entonces
							SalPar=48*CostoHrN
							HrEx=HrT-48
							Limpiar pantalla
							Escribir , NomT " Tiene ", HrEx " Horas Extras"
							Escribir "El salario Parcial de ", NomT " Es: $", SalPar
							SalarioF=SalPar+(HrEx*(CostoHrN*2))
							Escribir "El salario de ", NomT " con Horas extras es: $", SalarioF
							Si SalarioF>5000 Entonces
								Escribir , NomT " Haz ganado un Estímulo del 5%"
								SalarioF=SalarioF+(SalarioF*.05)
								Escribir "Tu salario con estímulo es de : $", SalarioF
							SiNo
								Limpiar pantalla
								Escribir , NomT " No Tienes Horas Extras"
								Escribir , NomT " Tu salario Sin estímulo es de : $", SalarioF
								Escribir "Suerte para la próxima"
							Fin Si
							
						SiNo
							SalarioF=HrT*CostoHrN
							Si SalarioF>5000 Entonces
								Limpiar pantalla
								Escribir , NomT " No Tienes Horas Extras"
								Escribir "Aún así, Haz ganado un Estímulo del 5%"
								SalarioF=SalarioF+(SalarioF*.05)
								Escribir "Tu salario con estímulo es de : $", SalarioF
							SiNo
								Limpiar pantalla
								Escribir , NomT " No Tienes Horas Extras"	
								Escribir , NomT " Tu salario Sin estímulo es de : $", SalarioF
								Escribir "Suerte para la próxima"
							FinSi
						FinSi
						Escribir 'Quieres calcular el salario de otro trabajador? S/N '
						Leer Resp
					Hasta Que Resp='N'
				fin si
				
			3:
				Borrar pantalla
				Definir M1S1P1,M1S1P2,M1S1P3 Como Entero
				Definir M1S2P1,M1S2P2,M1S2P3 Como Entero
				Definir M1S3P1,M1S3P2,M1S3P3 Como Entero
				Definir PromM1S1,PromM1S2,PromM1S3,PromFinal Como Real
				
				Escribir"====Calcula el Promedio de Módulo===="
				Escribir "Introduce la calificación del primer parcial del M1S1P1"
				leer M1S1P1
				Escribir "Introduce la calificación del segundo parcial del M1S1P2"
				leer M1S1P2
				Escribir "Introduce la calificación del tercer parcial del M1S1P3"
				leer M1S1P3
				Si M1S1P1>=6 y M1S1P2>=6 y M1S1P3>=6 Entonces
					PromM1S1=(M1S1P1+M1S1P2+M1S1P3)/3
					limpiar pantalla
					Escribir "Tu promedio del M1S1 es: ", PromM1S1
				SiNo
					limpiar pantalla
					Escribir "Tu promedio del M1S1 no se puede calcular... "
					Escribir "Tienes algún parcial reprobado "
					Escribir "Estás en curso intersemestral "
				Fin Si
				
				Escribir "Introduce la calificación del primer parcial del M1S2"
				leer M1S2P1
				Escribir "Introduce la calificación del segundo parcial del M1S2"
				leer M1S2P2
				Escribir "Introduce la calificación del tercer parcial del M1S2"
				leer M1S2P3
				Si M1S2P1>=6 y M1S2P2>=6 y M1S2P3>=6 Entonces
					PromM1S2=(M1S2P1+M1S2P2+M1S2P3)/3
					limpiar pantalla
					Escribir "Tu promedio del M1S2 es: ", PromM1S2
				SiNo
					limpiar pantalla
					Escribir "Tu promedio del M1S2 no se puede calcular... "
					Escribir "Tienes algún parcial reprobado "
					Escribir "Estás en curso intersemestral "
				Fin Si
				
				
				Escribir "Introduce la calificación del primer parcial del M1S3"
				leer M1S3P1
				Escribir "Introduce la calificación del segundo parcial del M1S3"
				leer M1S3P2
				Escribir "Introduce la calificación del tercer parcial del M1S3"
				leer M1S3P3
				Si M1S3P1>=6 y M1S3P2>=6 y M1S3P3>=6 Entonces
					PromM1S3=(M1S3P1+M1S3P2+M1S3P3)/3
					limpiar pantalla
					Escribir "Tu promedio del M1S3 es: ", PromM1S3
				SiNo
					limpiar pantalla
					Escribir "Tu promedio del M1S3 no se puede calcular... "
					Escribir "Tienes algún parcial reprobado "
					Escribir "Estás en curso intersemestral "
				Fin Si
				Limpiar Pantalla
				Escribir "El promedio del M1S1 es: ", PromM1S1
				Escribir "El promedio del M1S2 es: ", PromM1S2
				Escribir "El promedio del M1S3 es: ", PromM1S3
				Si PromM1S1=0 o PromM1S2=0 o PromM1S3=0 Entonces
					Escribir "No se puede calcular tu promedio Final hasta que te regularices "
					PromFinal=0
				SiNo
					
					PromFinal=(PromM1S1+PromM1S2+PromM1S3)/3
					Escribir "El promedio del M1: ", PromFinal
				Fin Si
				Si PromFinal>=8 Entonces
					Escribir "Felicidades, aún no estas en tesis "
					
				SiNo
					Si PromFinal>=6 Entonces
						Escribir "Lo siento, tu promedio final es: ", PromFinal " a darle a tu tesis.... "
					SiNo
						Escribir "Lo siento, tu promedio final es: ", PromFinal " a regularizarse.... "
					Fin Si
					
				Fin Si
				Escribir 'Quieres calcular otro promedio? S/N '
				Leer Resp
				Si Resp="S" Entonces
					
					Repetir
						Borrar pantalla
						
						Escribir"====Calcula el Promedio de Módulo===="
						Escribir "Introduce la calificación del primer parcial del M1S1P1"
						leer M1S1P1
						Escribir "Introduce la calificación del segundo parcial del M1S1P2"
						leer M1S1P2
						Escribir "Introduce la calificación del tercer parcial del M1S1P3"
						leer M1S1P3
						Si M1S1P1>=6 y M1S1P2>=6 y M1S1P3>=6 Entonces
							PromM1S1=(M1S1P1+M1S1P2+M1S1P3)/3
							limpiar pantalla
							Escribir "Tu promedio del M1S1 es: ", PromM1S1
						SiNo
							limpiar pantalla
							Escribir "Tu promedio del M1S1 no se puede calcular... "
							Escribir "Tienes algún parcial reprobado "
							Escribir "Estás en curso intersemestral "
						Fin Si
						
						Escribir "Introduce la calificación del primer parcial del M1S2"
						leer M1S2P1
						Escribir "Introduce la calificación del segundo parcial del M1S2"
						leer M1S2P2
						Escribir "Introduce la calificación del tercer parcial del M1S2"
						leer M1S2P3
						Si M1S2P1>=6 y M1S2P2>=6 y M1S2P3>=6 Entonces
							PromM1S2=(M1S2P1+M1S2P2+M1S2P3)/3
							limpiar pantalla
							Escribir "Tu promedio del M1S2 es: ", PromM1S2
						SiNo
							limpiar pantalla
							Escribir "Tu promedio del M1S2 no se puede calcular... "
							Escribir "Tienes algún parcial reprobado "
							Escribir "Estás en curso intersemestral "
						Fin Si
						
						
						Escribir "Introduce la calificación del primer parcial del M1S3"
						leer M1S3P1
						Escribir "Introduce la calificación del segundo parcial del M1S3"
						leer M1S3P2
						Escribir "Introduce la calificación del tercer parcial del M1S3"
						leer M1S3P3
						Si M1S3P1>=6 y M1S3P2>=6 y M1S3P3>=6 Entonces
							PromM1S3=(M1S3P1+M1S3P2+M1S3P3)/3
							limpiar pantalla
							Escribir "Tu promedio del M1S3 es: ", PromM1S3
						SiNo
							limpiar pantalla
							Escribir "Tu promedio del M1S3 no se puede calcular... "
							Escribir "Tienes algún parcial reprobado "
							Escribir "Estás en curso intersemestral "
						Fin Si
						Limpiar Pantalla
						Escribir "El promedio del M1S1 es: ", PromM1S1
						Escribir "El promedio del M1S2 es: ", PromM1S2
						Escribir "El promedio del M1S3 es: ", PromM1S3
						Si PromM1S1=0 o PromM1S2=0 o PromM1S3=0 Entonces
							Escribir "No se puede calcular tu promedio Final hasta que te regularices "
							PromFinal=0
						SiNo
							
							PromFinal=(PromM1S1+PromM1S2+PromM1S3)/3
							Escribir "El promedio del M1: ", PromFinal
						Fin Si
						Si PromFinal>=8 Entonces
							Escribir "Felicidades, aún no estas en tesis "
							
						SiNo
							Si PromFinal>=6 Entonces
								Escribir "Lo siento, tu promedio final es: ", PromFinal " a darle a tu tesis.... "
							SiNo
								Escribir "Lo siento, tu promedio final es: ", PromFinal " a regularizarse.... "
							Fin Si
							
						Fin Si
						
						Escribir 'Quieres calcular otro promedio? S/N '
						Leer Resp
					Hasta Que Resp='N'
				Fin Si
			4:
				Escribir 'HASTA PRONTO : '
				Escribir 'Espero haberte ayudado'
			De Otro Modo:
				Escribir 'SELECCIONAR UNA OPCIÓN VÁLIDA'
		FinSegun
		Escribir 'Presiona una tecla para continuar...'
		Esperar Tecla
	Hasta Que (Opción=4)
FinAlgoritmo
