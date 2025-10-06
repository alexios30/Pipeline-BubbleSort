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
                sh 'make'
            }
        }

        stage('Exécuter le tri') {
            steps {
                sh './bubblesort'
            }
        }

        stage('Tester (facultatif)') {
            steps {
                sh './test.sh'
            }
        }

        stage('Nettoyage') {
            steps {
                sh 'make clean'
            }
        }
    }
}
