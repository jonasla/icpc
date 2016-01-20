###################################################################################
#                                                                      	          #
#						getPDF version 2.0                           	          #
#																		          #
###################################################################################
#                                                        				          #
#	Estado actual: (no pongo tildes porque arma quilombo)              	          #
#		Al comenzar se despliega un menu donde nos da a elegir entre              #
#	descargar todo Live Archive o una Regional/World Final en particular.         #
#		Si se opta por lo primero, en el directorio donde esta el script se       #
#	crea una carpeta "Live Archive" donde se descargan todas las regionales       #
#	y World Finals.                                                               #
#		Si se opta por lo segundo, se despliega otro menu donde hay que           #
#	indicar el anho y luego otro menu donde hay que elegir la region de la        #
#	prueba. Una vez elegida la prueba, se crea una carpeta con el nombre          #
#	de la prueba elegida y se procede a descargar un .pdf por problema como       #
#	asi tambien un pdf con la concatenacion de todos los problemas.               #
#	                                                                   	          #
###################################################################################
#                                                                      	          #
#	Futuras mejoras:                                                   	          #
#		* En aquellos casos donde no hay un pdf de alta calidad        	          #
#		pero existe un pdf de menor calidad, descargar este ultimo.    	          #
#		* En aquellos casos donde no hay pdf alguno documentar         	          #
#		debidamente el hecho ocurrido. Por ejemplo con un archivo de   	          #
#		texto que explique lo ocurrido.                                	          #
#		                                                                          #
#																	 	          #
###################################################################################
#                                                                                 #
#	Mini Manual de Usuario:                                                       #
#                                                                                 #
#		1) Primero que nada hay que descargar 3 paquetes. Esto se puede           #
#                                                                                 #
#	hacer bastante facil si primero descargamos "pip", para lo cual               #
#	hay que poner en la terminal "sudo apt-get install python-pip".               #
#                                                                                 #
#		2) Instalar los 3 paquetes que mencionamos. Para esto ponemos             #
#                                                                                 #
#	en la terminal:                                                               #
#		"sudo pip install beautifulsoup4"                                         #
#		"sudo pip install requests"                                               #
#		"sudo pip install pyPDF2"                                                 #
#                                                                                 #
#		3) En: "usr/local/lib/python2.7/dist-packages/PyPDF2" hay que             #
#                                                                                 #
#		cambiar los permisos del arvhivo "generic.py" haciendo:                   #
#	"sudo chmod 777 /usr/local/lib/python2.7/dist-packages/PyPDF2/generic.py"     #
#                                                                                 #
#		4) En "generic.py" hay que modificar la linea 576 donde dice:             #
#                                                                                 #
#		if not data.get(key):                                                     #
#			data[key] = value                                                     #
#		elif pdf.strict:                                                          #
#			# multiple definitions of key not permitted                           #
#			raise utils.PdfReadError("Multiple definitions in dictionary ...      #
#		else:                                                                     #
#			warnings.warn("Multiple definitions in dictionary ...                 #
#                                                                                 #
#		y poner:                                                                  #
#                                                                                 #
#		if data.has_key(key):                                                     #
#			pass                                                                  #
#		else:                                                                     #
#			data[key] = value                                                     #
#                                                                                 #
#		5) Correr el script normalmente.                                          #
#		                                                                          #
###################################################################################                                                                   



import requests,os,bs4,sys
from PyPDF2 import PdfFileMerger

def getPageFromUrl(url):
	page = requests.get(url) 
	soup = bs4.BeautifulSoup(page.text) 
	links = soup.select('a') 
	return [page,soup,links]

def getPageFromLink(url,link):
	name = link.getText().replace('/'," - ")
	page,soup,links = getPageFromUrl(url + link.attrs['href']) 
	return [page,soup,links,name]

def linkFilt(links, s1 = 'Ap43JsNOhayCHANCEdeQUElePASESesteLINKa,RsZ1.,m', s2 = 'Ap43JsNOhayCHANCEdeQUElePASESesteLINKa,RsZ1.,m'):
	return [link for link in links if (link.attrs['href'][:5] == 'index' and not(link.getText() in ['Root','ICPC Archive Volumes',s1,s2])) ]

def downloadFromUrlToPath(url,nameOfFolder,nameOfFile):
		res = requests.get(url) 
		soupPDF = bs4.BeautifulSoup(res.text) 
		if ( len(soupPDF.select('h1')) == 0 and res.headers["Content-Length"] != "0"):
			pdf = open(os.path.join(nameOfFolder,nameOfFile + ".pdf"),"wb") 
			for chunk in res.iter_content(100000): 
				pdf.write(chunk)
			pdf.close()

def downloadRegionalFromLinkToPath(url,linksRegional,nameOfFolder,contestsYear,regional):
	os.makedirs(nameOfFolder)
	combined = PdfFileMerger()
	for linkRegional in linkFilt(linksRegional,contestsYear,regional):
		pageProblem,soupProblem,linksProblem,problem = getPageFromLink(url,linkRegional) 
		print problem 
		for linkProblem in linksProblem: 
			if ('.pdf' == linkProblem.attrs['href'][-4:]): 
				downloadFromUrlToPath(url + linkProblem.attrs['href'],nameOfFolder,problem)
				inpu = open(os.path.join(nameOfFolder,problem + ".pdf"),"rb") 
				combined.append(inpu) 
	outpu = open(os.path.join(nameOfFolder,contestsYear + " - " + regional + ".pdf"),"wb")
	combined.write(outpu) 
	print " - - - - "
	

	
requests.packages.urllib3.disable_warnings() # Esto hace falta en mi maquina, no se si es necesario siempre.

rootUrl = 'https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8'
url = "https://icpcarchive.ecs.baylor.edu/" 

pageRoot,soupRoot,linksRoot = getPageFromUrl(rootUrl)

print "_______________________________________________________________"
print "Desea descargar una prueba en particular o todo Live Archive?"
print "1 -> Todo Live Archive"
print "2 -> Regional/World Final particular"

opcion = int(sys.stdin.readline())

if opcion == 1:
	os.makedirs('Live Archive') 
	print "Comienza la descarga de Live Archive... (muchas horas restantes)"
	for linkRoot in linkFilt(linksRoot):   
		pageYear,soupYear,linksYear,contestsYear = getPageFromLink(url,linkRoot)
		os.makedirs('Live Archive/' + contestsYear) 
		print "--------------\n--------------"
		print contestsYear  
		print "--------------\n--------------"
		for linkYear in linkFilt(linksYear,contestsYear): 
			pageRegional,soupRegional,linksRegional,regional = getPageFromLink(url,linkYear)
			print regional
			print " - - - - "
			downloadRegionalFromLinkToPath(url,linksRegional,'Live Archive/' + contestsYear + "/" + regional,contestsYear,regional)

else:
	print "World Final o Regional?"
	print "1 -> World Final"
	print "2 -> Regional"
	opcionWFoR = int(sys.stdin.readline())
	if opcionWFoR == 1:
		print "Cual de estas? (por favor, espere a que termine de cargar la lista)"
		pageYear,soupYear,linksYear,contestsYear = getPageFromLink(url,linksRoot[19])
		WFList = list(enumerate(linkFilt(linksYear,contestsYear)))
		for i,linkYear in WFList:
			pageRegional,soupRegional,linksRegional,regional = getPageFromLink(url,linkYear)
			print i+1,"->",regional
		print "(carga de lista completa)"
		prueba = int(sys.stdin.readline())
		pageRegional,soupRegional,linksRegional,regional = getPageFromLink(url,WFList[prueba-1][1])
		print "--------------\n--------------"
		print contestsYear  
		print "--------------\n--------------"
		print regional
		print " - - - - "
		downloadRegionalFromLinkToPath(url,linksRegional,regional,contestsYear,regional)
	else:
		print "De que anho? (por favor, espere a que termine de cargar la lista)"
		RegionalList = list(enumerate(linkFilt(linksRoot,"World Finals")))
		for i,linkRoot in RegionalList:
			pageYear,soupYear,linksYear,contestsYear = getPageFromLink(url,linkRoot)
			print i+1,"->",contestsYear
		print "(carga de lista completa)"
		anho = int(sys.stdin.readline())
		pageYear,soupYear,linksYear,contestsYear = getPageFromLink(url,RegionalList[anho-1][1])
		print "--------------"
		print contestsYear
		print "--------------"
		print "Que region? (por favor, espere a que termine de cargar la lista)"
		AreaList = list(enumerate(linkFilt(linksYear,contestsYear)))
		for i, linkYear in AreaList:
			pageRegional,soupRegional,linksRegional,regional = getPageFromLink(url,linkYear)
			print i+1,"->",regional
		print "(carga de lista completa)"
		prueba = int(sys.stdin.readline())
		pageRegional,soupRegional,linksRegional,regional = getPageFromLink(url,AreaList[prueba-1][1])
		print "--------------\n--------------"
		print contestsYear  
		print "--------------\n--------------"
		print regional
		print " - - - - "
		downloadRegionalFromLinkToPath(url,linksRegional,contestsYear + " - " + regional,contestsYear,regional)
		
		
print "Descarga Finalizada"
		
