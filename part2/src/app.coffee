FlickrSearch = angular.module "FlickrSearch", ["infinite-scroll"]

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

  $scope.images = []

  $scope.search = ->
    Flickr.search($scope.query).then (res) ->
      $scope.images = res.data.items
      return
    return

  $scope.loadMore = ->
    Flickr.search($scope.query).then (res) ->
      for item in res.data.items
        $scope.images.push item
      return
    return
  return
