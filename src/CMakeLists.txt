add_executable(BaseProject main.cpp) #nom à changer

target_link_libraries(BaseProject PUBLIC sfml::sfml
# ou selon les besoins : sfml-system sfml-window sfml-graphics ...
)
