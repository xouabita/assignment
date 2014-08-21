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
  busy: false
  images: []


FlickrSearch.controller "flickrCtrl", ($scope,Flickr) ->

  $scope.images = []
  $scope.rowHeight = 

  $scope.search = ->
    Flickr.search($scope.query).then (res) ->
      $scope.images = res.data.items
      return
    return

  $scope.loadMore = ->
    return if Flickr.busy
    Flickr.busy = true
    Flickr.search($scope.query, $scope.page).then (res) ->
      for item in res.data.items
        $scope.images.push item
      Flickr.busy = false
      return
    return
  return

FlickrSearch.directive "photo", ->
  restrict: 'E'
  scope:
    phUrl: '@'
    phWidth: '@'
    phHeight: '@'
  template: '<div class="photo" ><img src="{{ phUrl }}" /></div>'
