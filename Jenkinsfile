pipeline {
    agent {
        docker { image 'gcc:latest' }
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

        stage('Tests unitaires et intégration') {
            steps {
                sh './test.sh'
            }
        }

        stage('Exécuter le programme') {
            steps {
                sh './bubblesort'
            }
        }
    }
}
