pipeline {
    agent any  

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

        stage('Test') {
            steps {
                sh './test.sh'
            }
        }
    }
}
