import time
start_time = time.time()

project_name     = "cmath_tests"
output_name      = f"{project_name}"
cc               = ""
preprocessor     = ""
warnings         = ""
include_folders  = ""
src              = ""
compiler_options = ""
libs             = ""
linker_options   = ""

import os
import sys

def set_src():

    global src
    
    src += """
    ./src/test_main.c
    """

    
def set_command_line_options():
    set_src()

    global cc
    global output_name
    global preprocessor    
    global warnings        
    global include_folders 
    global compiler_options
    global libs           
    global linker_options

    
    if sys.platform == "linux":
        output_name = output_name + ".a"
        
    elif sys.platform == "win32":
        output_name = output_name + ".exe"

    
    cc               = "gcc"
    
    if cc == "gcc":
        preprocessor += ""
        
        warnings += """
        -Wformat=2 
        -Wmain 
        -Wparentheses 
        -Wuninitialized
        -Wsign-compare 
        -Werror
        """
            
        include_folders += """
        -I ../
        """

        compiler_options += """ 
        -O3
        """
            
        libs += """
        """
            
        linker_options += f"""-o ./build/{output_name}"""
            
    
    elif cc == "cl":
        if sys.platform == "win32":
            preprocessor     += ""

            warnings += """
            /WX
            """
            
            include_folders += """
            -I ../
            """
            compiler_options += """ 
            /nologo 
            /Fo./build/obj/ 
            /O2
            """
            
            libs += """
            """
            
            linker_options += f"""/link /OUT:./build/{output_name} /PDB:./build/vc140.pdb"""
    else:
        print("unknown cc");
    
def main():

    # === set working directory ===
    os.chdir(os.path.dirname(os.path.realpath(__file__)))
    cwd = os.getcwd()

    # === create build dir ===
    if not os.path.isdir("build"):
        os.makedirs("build", 0o666)

    if not os.path.isdir("build/obj"):
        os.makedirs("build/obj/", 0o666)
    
    # === build and link ===
    command = f"{cc} {compiler_options} {warnings} {preprocessor} {include_folders} {src} {libs} {linker_options}".replace('\n', ' ');
    command = f"{cc} {compiler_options} {warnings} {preprocessor} {include_folders} {src} {libs} {linker_options}".replace('\n', ' ');
    command = " ".join(command.split())
    
    print(command);
    os.system(command);
    
    print_exit_time()
    

# windows doesn't have a nice time command, so we use this instead
def print_exit_time():
    global start_time
    end_time = time.time()
    print("time: {:.2f}s".format(end_time - start_time))

if __name__ == "__main__":
    set_command_line_options()
    main()

