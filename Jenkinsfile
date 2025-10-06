pipeline {
    agent any

    stages {
        stage('Cloner le dépôt') {
            steps {
                git 'https://ton-repo.git' // Remplace par l’URL de ton repo Git
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
