include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/scribus
)

set(SXW_IM_PLUGIN_MOC_CLASSES
	sxwdia.h
)

set(SXW_IM_PLUGIN_SOURCES
	contentreader.cpp
	sxwdia.cpp
	sxwim.cpp
	stylereader.cpp
)

set(SCRIBUS_SXW_IM_PLUGIN "sxwimplugin")

QT5_WRAP_CPP(SXW_IM_PLUGIN_MOC_SOURCES ${SXW_IM_PLUGIN_MOC_CLASSES})

add_library(${SCRIBUS_SXW_IM_PLUGIN} MODULE ${SXW_IM_PLUGIN_SOURCES} ${SXW_IM_PLUGIN_MOC_SOURCES})

target_link_libraries(${SCRIBUS_SXW_IM_PLUGIN} ${PLUGIN_LIBRARIES})

if(WANT_PCH)
	target_precompile_headers(${SCRIBUS_SXW_IM_PLUGIN} PRIVATE "../../plugins_pch.h")
endif()

install(TARGETS ${SCRIBUS_SXW_IM_PLUGIN}
	LIBRARY
	DESTINATION ${PLUGINDIR}gettext
	PERMISSIONS ${PLUGIN_PERMISSIONS}
)

# set_target_properties(${SCRIBUS_FONTPREVIEW_PLUGIN} PROPERTIES VERSION "0.0.0")
