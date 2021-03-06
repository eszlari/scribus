include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/scribus
	${POPPLER_INCLUDE_DIR}
	${POPPLER_CPP_INCLUDE_DIR}
)

set(IMPORTPDF_PLUGIN_UI_SRC
	pdfimportoptions.ui
)

set(IMPORTPDF_PLUGIN_MOC_CLASSES
	importpdf.h
	importpdfplugin.h
	pdfimportoptions.h
)

set(IMPORTPDF_PLUGIN_SOURCES
	importpdf.cpp
	importpdfplugin.cpp
	pdfimportoptions.cpp
	slaoutput.cpp
)

if(HAVE_POPPLER)
	if(HAVE_LCMS1)
		add_definitions(-DUSE_CMS)
	endif()
	add_definitions(-DHAVE_FREETYPE_H)
endif()

set(SCRIBUS_IMPORTPDF_PLUGIN "importpdf")

QT5_WRAP_UI(IMPORTPDF_PLUGIN_UI_SOURCES ${IMPORTPDF_PLUGIN_UI_SRC} )
QT5_WRAP_CPP(IMPORTPDF_PLUGIN_MOC_SOURCES ${IMPORTPDF_PLUGIN_MOC_CLASSES})

add_library(${SCRIBUS_IMPORTPDF_PLUGIN} MODULE ${IMPORTPDF_PLUGIN_SOURCES} ${IMPORTPDF_PLUGIN_MOC_SOURCES} ${IMPORTPDF_PLUGIN_UI_SOURCES})

link_directories( /usr/local/lib )
target_link_libraries(${SCRIBUS_IMPORTPDF_PLUGIN} ${PLUGIN_LIBRARIES} ${POPPLER_LIBRARY})

if(WANT_PCH)
	target_precompile_headers(${SCRIBUS_IMPORTPDF_PLUGIN} PRIVATE "../../plugins_pch.h")
endif()

install(TARGETS ${SCRIBUS_IMPORTPDF_PLUGIN}
	LIBRARY
	DESTINATION ${PLUGINDIR}
	PERMISSIONS ${PLUGIN_PERMISSIONS}
)

add_dependencies(${SCRIBUS_IMPORTPDF_PLUGIN} ${EXE_NAME})

# set_target_properties(${SCRIBUS_FONTPREVIEW_PLUGIN} PROPERTIES VERSION "0.0.0")
