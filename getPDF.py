#########################################################################
#                                                                      	#
#						getPDF version 1.2                             	#
#																		#
#########################################################################	   
#                                                        				#
#	Estado actual: (no pongo tildes porque arma quilombo)              	#
#		En la carpeta donde se situa el script genera una carpeta con  	#
#	el nombre "Live Archive" donde se comienzan a descargar todas las  	#
#	regionales/world finals que hay en Live Archive en formato de pdf. 	#
#	No se descargan aquellas regionales/world finals en las que el     	#
#	boton "PDF" de Live Archive no funciona (incluso cuando hay un pdf 	#
#	de menor calidad en la pagina del problema). Las regionales/ world 	#
#	finals se guardan en carpetas y subcarpetas con sus respectivos    	#
#	nombres adentro de la carpeta "Live Archive". Ademas de descargar  	#
#	un pdf por cada por cada problema, por cada regional/world final se	#
#	genera un pdf con todos los problemas de la prueba.                	#
#	                                                                   	#
#########################################################################	
#                                                                      	#
#	Futuras mejoras:                                                   	#
#		* En aquellos casos donde no hay un pdf de alta calidad        	#
#		pero existe un pdf de menor calidad, descargar este ultimo.    	#
#		* En aquellos casos donde no hay pdf alguno documentar         	#
#		debidamente el hecho ocurrido. Por ejemplo con un archivo de   	#
#		texto/pdf que explique lo ocurrido.                             #
#																	 	#
#########################################################################                                                                      



import requests,os,bs4
from PyPDF2 import PdfFileMerger

# Hay que instalar los paquetitos "PyPDF2", "requests" y "bs4". Se pueden instalar con: "sudo pip install xxxx" (con xxxx = nombre del paquetito)
	
requests.packages.urllib3.disable_warnings() # Esto hace falta en mi maquina, no se si es necesario siempre.
rootUrl = 'https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8'
url = "https://icpcarchive.ecs.baylor.edu/" 


os.makedirs('Live Archive') 
page = requests.get(rootUrl) 
soup = bs4.BeautifulSoup(page.text) 
links = soup.select('a') 
for link in links: 
	if 'index' == link.attrs['href'][:5] and link.getText() != 'Root' and link.getText() != 'ICPC Archive Volumes': 
		print "--------------\n--------------"
		contestsYear = link.getText().replace("/"," - ")
		print contestsYear  
		os.makedirs('Live Archive/' + contestsYear) 
		print "--------------\n--------------"
		pageYear = requests.get(url + link.attrs['href']) 
		soupYear = bs4.BeautifulSoup(pageYear.text) 
		linksYear = soupYear.select('a') 
		for linkYear in linksYear: 
			if 'index' == linkYear.attrs['href'][:5] and linkYear.getText() != 'Root' and linkYear.getText() != link.getText(): 
				regional = linkYear.getText().replace("/"," - ")
				print regional
				os.makedirs('Live Archive/' + contestsYear + "/" + regional)
				print " - - - - "
				pageRegional = requests.get(url + linkYear.attrs['href']) 
				soupRegional = bs4.BeautifulSoup(pageRegional.text) 
				linksRegional = soupRegional.select('a') 
				combined = PdfFileMerger()
				for linkRegional in linksRegional:
					if 'index' == linkRegional.attrs['href'][:5] and linkRegional.getText() != 'Root' and linkRegional.getText() != link.getText() and linkRegional.getText() != linkYear.getText(): 
						problem = linkRegional.getText().replace("/"," - ") 
						print problem 
						pageProblem = requests.get(url + linkRegional.attrs['href']) 
						soupProblem = bs4.BeautifulSoup(pageProblem.text) 
						linksProblem = soupProblem('a') 
						for linkProblem in linksProblem: 
							if ('.pdf' == linkProblem.attrs['href'][-4:]): 
								res = requests.get(url + linkProblem.attrs['href']) 
								soupPDF = bs4.BeautifulSoup(res.text) 
								if ( len(soupPDF.select('h1')) == 0): 
									pdf = open(os.path.join('Live Archive/' + contestsYear + "/" + regional,problem),"wb") 
									for chunk in res.iter_content(100000): 
										pdf.write(chunk)				   
									pdf.close()	
									inpu = open(os.path.join('Live Archive/' + contestsYear + "/" + regional,problem),"rb") 
									combined.append(inpu) 
				outpu = open(os.path.join('Live Archive/' + contestsYear + "/" + regional,contestsYear + " - " + regional),"wb")
				combined.write(outpu) 
				print " - - - - "
		
		


