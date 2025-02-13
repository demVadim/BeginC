
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window); 

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout<<"glfwInit failed"<<std::endl;
        return -1;
    }

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout<<"\n glfwCreateWindow failed \n"<<std::endl;
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
    glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);
    //init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    /* Loop until the user closes the window */
    
    while (!glfwWindowShouldClose(pWindow))
    {
        processInput(pWindow);
        /* Render here */
        glClearColor(0.0, 0.7, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glBegin(GL_TRIANGLES);

        glVertex2f(0.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *pWindow)
{
    if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, true);
}

void framebuffer_size_callback(GLFWwindow* pWindow, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}