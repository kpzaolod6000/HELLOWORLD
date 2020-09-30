# Proyecto BD II
Aplicacion de un Restaurante con Base de Datos Distribuidas usando QT Creator.

_Las lineas de comando del git_
HOLA GENTE!!!!!

Cree un repositorio en mi cuenta de GitHub:

llamada Proyecto-BD

Se uso primeramente el siguiente comando que contenia el README
git clone https://github.com/kpzaolod6000/Proyecto-BD.git

El proyecto se realizo poco a poco agreagando archivos al repositorio
git add image

git add Restaurante

git add RestSucursal

git add elegante.jpg

git add ppt_slide.jpg

Despues se procedio a comfirmar los archivos para su envio
git commit -m ""

Tambien se tuvo que agregar la direccion de repositorio github
git remote add origin https://github.com/kpzaolod6000/Proyecto-BD.git

Se envian a la rama master del repositorio
git push origin master

se creo una rama llamado version_local en la cual se realizo los mismo procedimiento,
como tambien clonar los archivos

git branch version_local

git checkout version_local

git add Restaurante

git add image

git add elegante.jpg

git add ppt_slide.jpg

git push origin version_local

git checkout master

git merge version_local

git log --oneline --decorate --all --graph

posteriormente se hizo los tags llamados v1.0.0 y v1.0.1

git tag -a v1.0.0 cf2d3dc55c0e7c5cc058bf1ee4f9e7ff715fb829 -m "Version Incompleta"

git tag -a v1.0.1 4824628fe31491c2ad6ee02e4cd086313aa6bc1b -m "Version Completa"

git tag -l "*"  -> para verificar todos los tags

git log -> para verificar las key de los commits

git push origin --tags

# Reporte de Defectos generado por SonarQube 

El scanner no se dio ningun error a pesar de que el plugin sonar-cxx-plugin-2.0.0.2202 fue instalado

https://github.com/kpzaolod6000/Proyecto-BD/blob/master/error1.png

https://github.com/kpzaolod6000/Proyecto-BD/blob/master/error2.png

https://github.com/kpzaolod6000/Proyecto-BD/blob/master/error.png
