
function(force_redefine_file_macro_for_sources targetname)  
    # 获取目标的所有源文件  
    get_target_property(source_files "${targetname}" SOURCES)  
    foreach(sourcefile ${source_files})  
        # 尝试获取源文件的当前编译定义列表（但这实际上不会获取到__FILE__的值）  
        get_property(defs SOURCE "${sourcefile}" PROPERTY COMPILE_DEFINITIONS)  
        # 获取源文件在项目目录中的相对路径  
        get_filename_component(filepath "${sourcefile}" ABSOLUTE)  
        string(REPLACE ${PROJECT_SOURCE_DIR}/ "" relpath ${filepath})  
        # 尝试将相对路径作为编译定义添加到列表中（但这不会改变__FILE__宏）  
        list(APPEND defs "__FILE__=\"${relpath}\"")  
        # 尝试设置更新后的编译定义到源文件上（但这不会按预期工作）  
        set_property(  
            SOURCE "${sourcefile}"  
            PROPERTY COMPILE_DEFINITIONS ${defs}  
        )  
    endforeach()  
endfunction()

function(algocc_add_include algoccpaths) 
    # 向项目添加Algocc相关的多个包含目录
    include_directories(${algoccpaths}/yaml/include    
                        ${algoccpaths}/jsoncpp/include                
                        ${algoccpaths}/logger
                        ${algoccpaths}/thread
                        ${algoccpaths}/base
                        ${algoccpaths}/xml
                        ${algoccpaths}/ini
                        ${algoccpaths}/socket
                        ${algoccpaths}/iomultiplex
                        ${algoccpaths}/plugin
                        ${algoccpaths}/msh
                        ${algoccpaths}/rpc
                        ${algoccpaths}/allocater) 
endfunction()
