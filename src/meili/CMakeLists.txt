file(GLOB headers ${VALHALLA_SOURCE_DIR}/valhalla/meili/*.h)

set(sources
  viterbi_search.cc
  topk_search.cc
  routing.cc
  candidate_search.cc
  transition_cost_model.cc
  map_matcher.cc
  map_matcher_factory.cc
  match_route.cc
  traffic_segment_matcher.cc)

valhalla_module(NAME meili
  SOURCES ${sources}
  HEADERS ${headers}
  INCLUDE_DIRECTORIES
    PUBLIC
      ${VALHALLA_SOURCE_DIR}
      ${VALHALLA_SOURCE_DIR}/valhalla
    PRIVATE
      ${VALHALLA_SOURCE_DIR}/third_party/rapidjson/include
      ${CMAKE_BINARY_DIR}
  DEPENDS
    valhalla::sif)
