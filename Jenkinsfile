pipeline {
    agent {
        docker { 
            image 'gcc:latest'   
        }
    }

    stages {
        stage('Cloner le dépôt') {
            steps {
                git(
                    url: 'https://github.com/alexios30/Pipeline-BubbleSort',
                    branch: 'main',
                    credentialsId: 'pipeline-dev'
                )
            }
        }

        stage('Compiler') {
            steps {
                sh 'gcc -o bubblesort bubblesort.c'
            }
        }

        stage('Exécuter le programme') {
            steps {
                sh './bubblesort'
            }
        }

        stage('Test (optionnel)') {
            steps {
                sh './test.sh'
            }
        }

        stage('Nettoyage') {
            steps {
                sh 'rm -f bubblesort'
            }
        }
    }
}
