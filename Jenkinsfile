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
                script {
                    try {
                        sh './compile.sh'
                    } catch (Exception e) {
                        echo "Erreur lors de la compilation: ${e.getMessage()}"
                        currentBuild.result = 'FAILURE'
                        error("Compilation échouée")
                    }
                }
            }
        }

        stage('Exécuter le programme') {
            steps {
                script {
                    try {
                        sh './run.sh'
                    } catch (Exception e) {
                        echo "Erreur lors de l'exécution: ${e.getMessage()}"
                        currentBuild.result = 'FAILURE'
                        error("Exécution échouée")
                    }
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    try {
                        sh './test.sh'
                    } catch (Exception e) {
                        echo "Erreur lors des tests: ${e.getMessage()}"
                        currentBuild.result = 'FAILURE'
                        error("Tests échoués")
                    }
                }
            }
        }
    }

    post {
        failure {
            echo "Pipeline échoué - Redémarrage possible"
            script {
                if (env.BUILD_NUMBER.toInteger() < 3) {
                    echo "Tentative de redémarrage automatique..."
                    build job: env.JOB_NAME, wait: false
                }
            }
        }
        always {
            echo "Pipeline terminé"
        }
        success {
            echo "Pipeline réussi !"
        }
    }
}
