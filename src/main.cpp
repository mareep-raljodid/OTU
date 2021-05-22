// Dear ImGui: standalone example application for Allegro 5
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "imgui.h"
#include "ImGui_SDK_helper.h"
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#define MAX_LEN 256

inline bool file_check (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

bool startROS(char *f, char *p)
{
    char buffer[1025] = "";
    snprintf ( buffer, 1025, "roslaunch %s %s", p, f );  
	std::cout << "[DBG] ROS COMMAND buffer: "<< buffer << std::endl;
    bool file_stat = file_check(f);
    int status = system(buffer);
    
    if (!file_stat){
        std::cout << "[DBG] [File Absent] Error: " << strerror(errno) << '\n';
        return false;
    }
    
    else
    {
        if (WIFEXITED(status))
            std::cout << "[DBG] ROS COMMAND SUCCESSFUL, exit code " << WEXITSTATUS(status) << '\n';
        else
            std::cout << "[DBG] ROS COMMAND EXIT abnormal\n";
        return true;
    }
}

int main(int, char**)
{
    // Setup Allegro
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY* display = al_create_display(1280, 720);
    al_set_window_title(display, "ODOT Project");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplAllegro5_Init(display);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    bool show_demo_window = false;
    bool show_another_window = false;
    bool ros_fail = false;
    bool ros_running = false;
    bool ros_bag_needed = false;
    bool ros_bag_started = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
            char f[MAX_LEN] = "";
            char p[MAX_LEN] = "";
            static int counter = 0;


    // Main loop
    bool running = true;
    while (running)
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        ALLEGRO_EVENT ev;
        while (al_get_next_event(queue, &ev))
        {
            ImGui_ImplAllegro5_ProcessEvent(&ev);
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;
            if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
            {
                ImGui_ImplAllegro5_InvalidateDeviceObjects();
                al_acknowledge_resize(display);
                ImGui_ImplAllegro5_CreateDeviceObjects();
            }
        }

        // Start the Dear ImGui frame
        ImGui_ImplAllegro5_NewFrame();
        ImGui::NewFrame();

        char* curr_path;
        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        bool clrData = false;
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {

            ImGui::Begin("ODOT Project [ROS SENSOR SPAWN]");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("Current feature set in this release: Sensor spawning [roslaunch exec.]");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Start Data collection (foreground, realtime)", &show_another_window);

            ImGui::InputText("<- ROS Launch File Path", f, MAX_LEN-1);   
            ImGui::InputText("<- ROS Package Name", p, MAX_LEN-1);
            ImGui::Checkbox("Clear collected", &clrData); 
            
	    if (ImGui::Button("Start ROS Sensors")){                         // Buttons return true when clicked (most widgets return true when edited/activated)
                ros_fail = !startROS(f,p);
                ros_running = startROS(f,p);
		ros_bag_needed = false;
	    }
	    
	    if (ImGui::Button("Start ROS Sensors and Bag logs")){                         // Buttons return true when clicked (most widgets return true when edited/activated)
                ros_fail = !startROS(f,p);
                ros_running = startROS(f,p);
		ros_bag_needed = true;
	    }
            ImGui::SameLine();
            ImGui::Text("Current Count = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
        if(clrData){
             curr_path = NULL;
            //clearData();
        }
        bool rc = true;
        // 3. Show another simple window.
        if (ros_fail)
        {
            ImGui::Begin("FAILED", &ros_fail);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            
            ImGui::Text("Path or Package name issue, please try again.");
            
            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
 
            if (ImGui::Button("Ok")){
                ros_fail = false;
            }
            ImGui::End();
        }
        if (ros_running)
        {
            ImGui::Begin("Sensors Spawned and bagging data", &ros_running);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	    if (!ros_bag_started && ros_bag_needed){
	    	system ("cd bags; mv latest/* older/.; cd latest; rosbag record -a &");
	    	ros_bag_started = true;
	    }
	    if (ros_bag_started && ros_bag_needed)
	    	ImGui::Text("Current data is being bagged at: OTU/bags/latest");
            ImGui::Text("Press STOP to stop");
            
            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
 
            if (ImGui::Button("STOP")){
                system("rosnode kill -a");
                ros_fail = false;
                ros_running = false;
            }
            ImGui::End();
        }
        if (show_another_window)
        {
            ImGui::Begin("Collection Status", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            
            ImGui::Text("Collecting to ./tmp/");
            
            int bit1 = 2;//readData();
            rc = true;//writeData(); //return true upon write successful
 
            if (ImGui::Button("Ok")){
                show_another_window = false;
            }
            ImGui::End();
        }
                   
        // Rendering
        ImGui::Render();
        al_clear_to_color(al_map_rgba_f(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w));
        ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
        al_flip_display();
    }

    // Cleanup
    ImGui_ImplAllegro5_Shutdown();
    ImGui::DestroyContext();
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
