pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git(
                    url: 'https://github.com/alexios30/Pipeline-BubbleSort',
                    branch: 'test',
                    credentialsId: 'pipeline-de'
                )
            }
        }

        stage('Install Dependencies') {
            steps {
                sh 'apt-get update && apt-get install -y gcc'
            }
        }

        stage('Build') {
            steps {
                echo '=== COMPILATION DU PROGRAMME ==='
                sh 'gcc -o bubblesort bubblesort.c'
            }
        }

        stage('Test') {
            steps {
                echo '=== TESTS ==='
                sh './bubblesort'
            }
        }
    }

    post {
        always {
            sh 'rm -f bubblesort'
        }
    }
}
