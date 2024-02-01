#include "SGA/SGA.hpp"
#include "TestRenderer.hpp"

const char* fragmentShaderPath = "../shader.frag";

const char* vertexShaderPath = "../shader.vert";

int main(int argc, char** argv) {
   SGA::Application application(argc, argv);
   TestRenderer testRenderer(1024, 768, "Test");

   application.setWindow(&testRenderer);

   SGA::ShaderProgram* shaderProgram = new SGA::ShaderProgram();

   SGA::VertexShader vertexShader(vertexShaderPath);
   SGA::FragmentShader fragmentShader(fragmentShaderPath);

   shaderProgram->addShader(&vertexShader);
   shaderProgram->addShader(&fragmentShader);

   shaderProgram->buildShaders();
   shaderProgram->doesProgramLink();
   shaderProgram->validate();

   shaderProgram->use();

   application.start();

   delete shaderProgram;
}
