idf_component_register(
                    SRCS "main.cpp" "Stepper.cpp" "StepperFsm.cpp" "MeasurementSystemFsm.cpp"
                    INCLUDE_DIRS ".")
set_property(TARGET ${COMPONENT_TARGET} PROPERTY CXX_STANDARD)
component_compile_options(-fexceptions -ggdb)
