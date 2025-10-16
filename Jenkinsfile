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
                timeout(time: 15, unit: 'SECONDS') {
                    sh 'chmod +x test.sh'
                    sh './test.sh'
                }
            }
        }
    }

    post {
        always {
            sh 'rm -f bubblesort'
        }
    }
}
