find_package(Gettext REQUIRED)

file(GLOB _po_files locale/*.po)
foreach(_po_file ${_po_files})
    get_filename_component( _po_name ${_po_file} NAME_WLE )
    list( APPEND LANGS ${_po_name} )
endforeach()

set(_domain "wxstd-${wxMAJOR_VERSION}.${wxMINOR_VERSION}")

foreach(lang ${LANGS})
    gettext_process_po_files(${lang} ALL PO_FILES locale/${lang}.po)
    
    set( _outpath "${CMAKE_INSTALL_PREFIX}/share/locale/${lang}" )
    install(DIRECTORY DESTINATION ${_outpath})
    
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${lang}.gmo DESTINATION ${_outpath} RENAME ${_domain}.mo)
    
    list( APPEND OUT_LANG_FILES "${_out_file}" )
endforeach()

add_custom_target( locale ALL
                   DEPENDS ${OUT_LANG_FILES} )