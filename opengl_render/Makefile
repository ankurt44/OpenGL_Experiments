CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)

OBJS = main.o display.o mesh.o shader.o stb_image.o texture.o obj_loader.o
INCLUDE_GLM = -I /Users/ank/Documents/git_projects/glm
INCLUDE_SDL = -I /Library/Frameworks/SDL2.framework/Headers 
FRAMEWORK_OpenGL = -F /Library/Frameworks/ -framework OpenGl -framework SDL2 

test_opengl : $(OBJS)
	$(CC) $(OBJS) -o test_opengl $(FRAMEWORK_OpenGL)

main.o : main.cpp display.h shader.h mesh.h texture.h transform.h camera.h
	$(CC) $(CFLAGS) main.cpp $(INCLUDE_SDL) $(INCLUDE_GLM)

display.o : display.cpp display.h 
	$(CC) $(CFLAGS) display.cpp $(INCLUDE_SDL)

mesh.o : mesh.cpp mesh.h obj_loader.h
	$(CC) $(CFLAGS) mesh.cpp $(INCLUDE_GLM)

shader.o : shader.cpp shader.h transform.h
	$(CC) $(CFLAGS) shader.cpp $(INCLUDE_GLM)

stb_image.o : stb_image.cpp stb_image.h
	$(CC) $(CFLAGS) stb_image.cpp

texture.o : texture.cpp texture.h stb_image.h
	$(CC) $(CFLAGS) texture.cpp

obj_loader.o: obj_loader.cpp obj_loader.h
	$(CC) $(CFLAGS) obj_loader.cpp $(INCLUDE_GLM)

clean:
	\rm *.o test_opengl
