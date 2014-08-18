FlickrSearch = angular.module "FlickrSearch", []

FlickrSearch.factory 'Flickr', ($http) ->
  search: (query) ->
    $http(
      method: 'JSONP'
      url: 'http://api.flickr.com/services/feeds/photos_public.gne'
      params:
        'format':'json'
        'jsoncallback':'JSON_CALLBACK'
        'tags': query
    ).success (data) -> return data

FlickrSearch.controller "flickrCtrl", ($scope,Flickr) ->
  $scope.search = ->
    Flickr.search($scope.query).then (res) ->
      $scope.images = res.data.items
      return
    return
  $scope.search()
  return
