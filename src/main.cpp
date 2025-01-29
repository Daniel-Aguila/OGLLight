#include <glad/glad.h> //Loader
#include <GLFW/glfw3.h> //context and window management
#include <iostream>

//forward functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//triangle (x,y,z)
//[-1.0,1.0]
float vertices[] ={
    -0.5f,-0.5f,0.0f,
    0.5f,-0.5f,0.0f,
    00.f,0.5f,0.0f,
};

int main() {

    //specify configuration for OpenGL
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Window Object
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //store data into GPU
    //Vertex Buffer Objects(VBO)
    unsigned int VBO;
    glGenBuffers(1,&VBO); //Generate one buffer id and have VBO reference it
    glBindBuffer(GL_ARRAY_BUFFER,VBO); //bind several buffers at once as long as they have diff buffer type.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copies the previously defined vertex data inside the  buffer memory
    //(Type of buffer we want to copy data into, size of the data in bytes, data we want to send, how gpu manages the data)



    glfwMakeContextCurrent(window);

    //get the address of the function pointers dynamically
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //initial viewport
    glViewport(0,0,800,600);
    //resize the window and viewport
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //render loop
    while (!glfwWindowShouldClose(window)) {

        //checks for input (key presses, etc)
        processInput(window);

        //render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //swaps front (user sees) and back (openGl) buffers prevents flickering or incomplete frames
        //draw on back buffer then when it is done, swap to front
        glfwSwapBuffers(window);
        //checks if any events were triggered (resizing, etc)
        glfwPollEvents();
    }

    //clean glfw resources
    glfwTerminate();
    return 0;
}
//resize framebuffer for viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, width, height);
}

//processes input
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}