pipeline {
    agent any

    stages {
        stage('Cloner le dépôt') {
            steps {
                git 'https://github.com/alexios30/Pipeline-BubbleSort'
            }
        }

        stage('Compiler') {
            steps {
                script {
                    if (isUnix()) {
                        sh 'gcc -o bubblesort bubblesort.c'
                    } else {
                        bat 'gcc -o bubblesort bubblesort.c'
                    }
                }
            }
        }

        stage('Exécuter le programme') {
            steps {
                script {
                    if (isUnix()) {
                        sh './bubblesort'
                    } else {
                        bat '.\\bubblesort.exe'
                    }
                }
            }
        }

        stage('Test (optionnel)') {
            steps {
                script {
                    if (isUnix()) {
                        sh './test.sh'
                    } else {
                        bat 'test.bat'
                    }
                }
            }
        }

        stage('Nettoyage') {
            steps {
                script {
                    if (isUnix()) {
                        sh 'rm -f bubblesort'
                    } else {
                        bat 'del bubblesort.exe'
                    }
                }
            }
        }
    }
}

def isWindows() {
    return System.getProperty('os.name').toLowerCase().contains('windows')
}
