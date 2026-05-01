# DevOps Exam - Spring Boot CI Pipeline

This repository contains a Spring Boot CRUD application and a Jenkins Pipeline configuration for continuous integration.

## Q3. Jenkins CI Pipeline Setup

### Answer:
To set up a Jenkins CI pipeline for a Spring Boot application, you need to:
1. **Pull code from repository**: Configure the Jenkins job to use Git and point it to the GitHub repository URL.
2. **Build using Maven**: Use the `mvn clean compile` command.
3. **Run test cases**: Use the `mvn test` command.
4. **Generate build artifact**: Use the `mvn package` command to create a `.jar` file in the `target/` directory.
add homasvikaneria
### Jenkins Pipeline (Declarative Syntax)

```groovy
pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Pulled automatically if configured in Jenkins job
                checkout scm
            }
        }

        stage('Build') {
            steps {
                // Windows uses 'bat', Linux uses 'sh'
                bat 'mvn clean compile'
            }
        }

        stage('Test') {
            steps {
                bat 'mvn test'
            }
        }

        stage('Package') {
            steps {
                bat 'mvn package'
            }
        }

        stage('Archive') {
            steps {
                archiveArtifacts artifacts: 'target/*.jar', fingerprint: true
            }
        }
    }
}
```

## Repository Structure
- `src/`: Application source code.
- `pom.xml`: Maven configuration.
- `Jenkinsfile`: Pipeline definition for Jenkins.
- `.gitignore`: Configured to exclude IDE files and build artifacts (target folder, etc.).
