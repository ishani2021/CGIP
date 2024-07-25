

    #define BLACK
    #include<stdio.h>
    #include<math.h>
    #include<GL/glut.h>
    GLfloat Triangle[3][3]={{100.0,250.0,175.0},{100.0,100.0,300.0},{1.0,1.0,1.0}};
    GLfloat rotatement[3][3]={{0},{0},{0}};
    GLfloat Result[3][3]={{0},{0},{0}};
    GLfloat m=0;
    GLfloat n=0;
    float theta;
    void triangle()
    {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(Triangle[0][0],Triangle[1][0]);
    glVertex2f(Triangle[0][1],Triangle[1][1]);
    glVertex2f(Triangle[0][2],Triangle[1][2]);
    glEnd();
    }
    void display()
    {
    glClear(GL_COLOR_BUFFER_BIT);
    triangle();
    glPushMatrix();
    glTranslatef(m,n,0);
    glRotatef(theta,0,0,1);
    glTranslatef(-m,-n,0);
    triangle();
    glPopMatrix();
    glFlush();
    }
    void myinit()
    {
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,449,0,499);
    }
    int main(int argc,char **argv)
    {
    int ch;
    printf("enter choice\n 1:Rotation about origin \n 2:rotation about a fixed point\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("enter the rotation angle in degree:");
    scanf("%f",&theta);
    break;
    case 2:printf("enter the fixed point:");
    scanf("%f%f",&m,&n);
    printf("enter the rotation angle:");
    scanf("%f",&theta);
    break;
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Triangle rotaion");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
    }
    #####################################################################################
    5
    ######################################################################################
    #include <stdlib.h>
    #include <GL/glut.h>
    GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-
    1.0,1.0}, {1.0,-
    1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
    GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0},
    {-1.0,-1.0,1.0} ,{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
    GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
    {0.0,0.0,1.0},{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
    static GLfloat theta[]={0.0,0.0,0.0};
    static GLint axis =2;
    void polygon(int a, int b, int c , int d)
    {/* draw a polygon via list of vertices */
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
    }
    void colorcube(void){
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
    }
    void display(void)
    {/* display callback, clear frame buffer and z buffer,
    rotate cube and draw, swap buffers */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    colorcube();
    glFlush();
    glutSwapBuffers();}
    void spinCube()
    {/* Idle callback, spin cube 2 degrees about selected axis*/
    theta[axis] += 0.1;
    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    /* display(); */
    glutPostRedisplay();
    }
    void mouse(int btn, int state, int x, int y)
    {/* mouse callback, selects an axis about which to rotate */
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
    }
    void myReshape(int w, int h)
    { glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
    2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
    glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
    2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    }
    void main(int argc, char **argv)
    {
    glutInit(&argc, argv);
    /* need both double buffering and z buffer */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating a Color Cube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST); /* Enable hidden surface--removal */
    glutMainLoop();
    }
    ######################################################################################
    6
    #######################################################################################
    #include <GL/glut.h>
    #include <math.h>
    #include <stdlib.h>
    const double TWO_PI = 6.2831853;
    GLsizei winWidth = 500, winHeight = 500; // Initial display window size.
    GLuint regHex; // Define name for display list.
    static GLfloat rotTheta = 0.0;
    struct scrPt
    {
    GLint x, y;
    };
    static void init (void)
    {
    struct scrPt hexVertex;
    GLdouble hexTheta;
    GLint k;
    glClearColor (1.0, 1.0, 1.0, 0.0);
    /* Set up a display list for a red regular hexagon.
    * Vertices for the hexagon are six equally spaced
    * points around the circumference of a circle.
    */
    regHex = glGenLists (1);
    glNewList (regHex, GL_COMPILE);
    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
    for (k = 0; k < 6; k++) {
    hexTheta = TWO_PI * k / 6;
    hexVertex.x = 150 + 100 * cos (hexTheta);
    hexVertex.y = 150 + 100 * sin (hexTheta);
    glVertex2i (hexVertex.x, hexVertex.y);
    }
    glEnd ( );
    glEndList ( );
    }
    void displayHex (void)
    {
    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix ( );
    glRotatef (rotTheta, 0.0, 0.0, 1.0);
    glCallList (regHex);
    glPopMatrix ( );
    glutSwapBuffers ( );
    glFlush ( );
    }
    void rotateHex (void)
    {
    rotTheta += 3.0;
    if (rotTheta > 360.0)
    rotTheta -= 360.0;
    glutPostRedisplay ( );
    }
    void winReshapeFcn (GLint newWidth, GLint newHeight)
    {
    glViewport (0, 0, (GLsizei) newWidth, (GLsizei) newHeight);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (-320.0, 320.0, -320.0, 320.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ( );
    glClear (GL_COLOR_BUFFER_BIT);
    }
    void mouseFcn (GLint button, GLint action, GLint x, GLint y)
    {
    switch (button) {
    case GLUT_MIDDLE_BUTTON: // Start the rotation.
    if (action == GLUT_DOWN)
    glutIdleFunc (rotateHex);
    break;
    case GLUT_RIGHT_BUTTON: // Stop the rotation.
    if (action == GLUT_DOWN)
    glutIdleFunc (NULL);
    break;
    default:
    break;
    }
    }
    int main (int argc, char** argv)
    {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition (150, 150);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Animation Example");
    init ( );
    glutDisplayFunc (displayHex);
    glutReshapeFunc (winReshapeFcn);
    glutMouseFunc (mouseFcn);
    glutMainLoop ( );
    return(0);}
    
    
    #################################################################
    7
    #################################################################
    import cv2
    import numpy as np
    import matplotlib.pyplot as plt
    # Read the image
    img = cv2.imread('rabbit.jpg')
    # Get the height and width of the image
    height, width = img.shape[:2]
    # Split the image into four quadrants
    quad1 = img[:height//2, :width//2]
    quad2 = img[:height//2, width//2:]
    quad3 = img[height//2:, :width//2]
    quad4 = img[height//2:, width//2:]
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.imshow(quad1)
    plt.title("1")
    plt.axis("off")
    plt.subplot(1, 2, 2)
    plt.imshow(quad2)
    plt.title("2")
    plt.axis("off")
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.imshow(quad3)
    plt.title("3")
    plt.axis("off")
    plt.subplot(1, 2, 2)
    plt.imshow(quad4)
    plt.title("4")
    plt.axis("off")
    plt.show()
    #####################################################################
    8
    ########################################################################
    import cv2
    import numpy as np
    
    def translate_image(image, dx, dy):
        rows, cols = image.shape[:2]
        translation_matrix = np.float32([[1, 0, dx], [0, 1, dy]])
        translated_image = cv2.warpAffine(image, translation_matrix, (cols, rows))
        return translated_image
    
    # Read the image
    image = cv2.imread('disney.jpeg')
    
    # Get image dimensions
    height, width = image.shape[:2]
    
    # Calculate the center coordinates of the image
    center = (width // 2, height // 2)
    rotation_value = int(input("Enter the degree of Rotation:"))
    rotated = cv2.getRotationMatrix2D(center=center, angle=rotation_value, scale=1)
    rotated_image = cv2.warpAffine(src=image, M=rotated, dsize=(width, height))
    
    scaling_value = int(input("Enter the zooming factor:"))
    # Create the 2D rotation matrix
    
    scaled = cv2.getRotationMatrix2D(center=center, angle=0, scale=scaling_value)
    scaled_image = cv2.warpAffine(src=rotated_image, M=scaled, dsize=(width, height))
    
    h = int(input("How many pixels you want the image to be translated horizontally? "))
    v = int(input("How many pixels you want the image to be translated vertically? "))
    translated_image = translate_image(scaled_image, dx=h, dy=v)
    
    cv2.imwrite('Final_image.png', translated_image)
    cv2.imshow("image" ,translated_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    #######################################################################################
    9
    ########################################################################################
    import cv2
    import numpy as np
    
    # Load the image
    image_path = "rabbit.jpg"  # Replace with the path to your image
    img = cv2.imread(image_path)
    
    # Convert the image to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    # Edge detection
    edges = cv2.Canny(gray, 100, 200)  # Use Canny edge detector
    
    # Texture extraction
    kernel = np.ones((5, 5), np.float32) / 25  # Define a 5x5 averaging kernel
    texture = cv2.filter2D(gray, -1, kernel)  # Apply the averaging filter for texture extraction
    
    # Display the original image, edges, and texture
    cv2.imshow("Original Image", img)
    cv2.imshow("Gray", gray)
    cv2.imshow("Edges", edges)
    cv2.imshow("Texture", texture)
    
    # Wait for a key press and then close all windows
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    ############################################################################
    10
    ###########################################################################
    import numpy as np 
    import cv2
    import matplotlib.pyplot as plt 
    
    img=cv2.imread('disney.jpeg',cv2.IMREAD_GRAYSCALE)
    image_array = np.array(img)
    print(image_array)
    def sharpen():
      return np.array([[1,1,1],[1,1,1],[1,1,1]])
    def filtering(image, kernel):
        m, n = kernel.shape
        if (m == n):
            y, x = image.shape[:2]
            y = y - m + 1 # shape of image - shape of kernel + 1
            x = x - m + 1
            new_image = np.zeros((y,x))
            for i in range(y):
                for j in range(x):
                    new_image[i][j] = np.sum(image[i:i+m, j:j+m]*kernel)
        return new_image
    # Display the original and sharpened images
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.imshow(image_array,cmap='gray')
    plt.title("Original Grayscale Image")
    plt.axis("off")
    
    plt.subplot(1, 2, 2)
    plt.imshow(filtering(image_array, sharpen()),cmap='gray')
    plt.title("Blurred Image")
    plt.axis("off")
    plt.show()
    ##################################################################################################
    11
    ################################################################################################
    import cv2
    import numpy as np
    
    image_path = 'moon2.jpg'
    image = cv2.imread(image_path)
    
    # Convert the image to grayscale (contours work best on binary images)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Apply thresholding (you can use other techniques like Sobel edges)
    _, binary_image = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    
    # Find contours
    contours, _ = cv2.findContours(binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Draw all contours on the original image
    cv2.drawContours(image, contours, -1, (0, 255, 0), 3)
    
    # Display the result
    cv2.imshow('Contours', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    #####################################################################################################
    12
    #####################################################################################################
    import cv2
    
    # Load the pre-trained Haar Cascade classifier for face detection
    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
    eye_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_eye.xml')
    
    # Read the input image 
    image_path = 'faces.jpg'
    image = cv2.imread(image_path)
    
    # Convert the image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Detect faces in the image
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5)
    
    # Draw rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 2)
    
    # Save or display the result
    cv2.imwrite('detected_faces.jpg', image)  # Save the result
    cv2.imshow('Detected Faces', image)  # Display the result
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    