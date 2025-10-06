pipeline {
    agent any

    environment {
        IS_WINDOWS = "${isWindows()}"
    }

    stages {
        stage('Cloner le dépôt') {
            steps {
                git 'https://github.com/alexios30/Pipeline-BubbleSort' 
            }
        }

        stage('Compiler') {
            steps {
                script {
                    if (isWindows()) {
                        bat 'gcc -o bubblesort bubblesort.c'
                    } else {
                        sh 'gcc -o bubblesort bubblesort.c'
                    }
                }
            }
        }

        stage('Exécuter le programme') {
            steps {
                script {
                    if (isWindows()) {
                        bat '.\\bubblesort.exe'
                    } else {
                        sh './bubblesort'
                    }
                }
            }
        }

        stage('Test (optionnel)') {
            steps {
                script {
                    if (isWindows()) {
                        bat 'test.bat'
                    } else {
                        sh './test.sh'
                    }
                }
            }
        }

        stage('Nettoyage') {
            steps {
                script {
                    if (isWindows()) {
                        bat 'del bubblesort.exe'
                    } else {
                        sh 'rm -f bubblesort'
                    }
                }
            }
        }
    }
}

// 🔍 Fonction pour détecter Windows
def isWindows() {
    return System.getProperty('os.name').toLowerCase().contains('windows')
}
