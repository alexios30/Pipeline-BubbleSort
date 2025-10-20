pipeline {
    agent any

    stages {
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
